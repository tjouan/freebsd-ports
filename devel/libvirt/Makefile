# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/ \
		ftp://libvirt.org/libvirt/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libssh2.so:${PORTSDIR}/security/libssh2
BUILD_DEPENDS=	dnsmasq:${PORTSDIR}/dns/dnsmasq \
		xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	dnsmasq:${PORTSDIR}/dns/dnsmasq \
		dmidecode:${PORTSDIR}/sysutils/dmidecode

OPTIONS_DEFINE=	DOCS GNUTLS NLS QEMU SASL
OPTIONS_DEFAULT=	GNUTLS
OPTIONS_DEFINE_amd64=	XEN
.if exists(/usr/sbin/bhyve)
OPTIONS_DEFINE_amd64+=	BHYVE
OPTIONS_DEFAULT_amd64+=	BHYVE
.else
PLIST_SUB+=		BHYVE="@comment "
CONFIGURE_ARGS+=	--without-bhyve
.endif
QEMU_DESC=	QEMU driver
BHYVE_DESC=	bhyve driver
XEN_DESC=	Xen support via libxl

OPTIONS_SUB=	yes

BHYVE_CONFIGURE_WITH=	bhyve

QEMU_CONFIGURE_WITH=	qemu yajl
QEMU_CFLAGS=	-I${LOCALBASE}/include
QEMU_LIB_DEPENDS=	libyajl.so:${PORTSDIR}/devel/yajl
QEMU_RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
			qemu-io:${PORTSDIR}/emulators/qemu-devel

GNUTLS_CONFIGURE_ON=	--with-gnutls=${LOCALBASE}
GNUTLS_CONFIGURE_OFF=	--without-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}

SASL_CONFIGURE_WITH=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

XEN_CONFIGURE_WITH=	libxl
XEN_CFLAGS=	-I${LOCALBASE}/include
XEN_LIB_DEPENDS=	libxenlight.so:${PORTSDIR}/sysutils/xen-tools

VARDIR=		/var

USE_RC_SUBR=	libvirtd virtlogd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-sysctl \
		--without-lxc \
		--without-uml \
		--without-xen \
		--without-login-shell \
		--with-ssh2 \
		--localstatedir=${VARDIR}

# random_data fix can be removed when 8.x is eol
CONFIGURE_ENV=	ac_cv_type_struct_random_data=""

# limit production release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

USES=		charsetfix cpe gmake libtool pathfix perl5 pkgconfig
CPE_VENDOR=	redhat
USE_PERL5=	build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHLIB_VER=	0.1003.${PORTVERSION:E}
PLIST_SUB+=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if !${PLIST_SUB:MXEN}
PLIST_SUB+=     XEN="@comment "
.endif

CONF_FILES=	\
		libvirt-admin.conf \
		libvirt.conf \
		libvirtd.conf \
		libxl.conf \
		qemu.conf \
		virtlockd.conf \
	   	virtlogd.conf

post-patch:
	@${REINPLACE_CMD} -e 's|ln -s ../default.xml|true|' \
			  -e 's|$$(DESTDIR)$$(confdir)/qemu/networks|${STAGEDIR}${EXAMPLESDIR}/networks|' \
			  ${WRKSRC}/src/Makefile.in

	@${REINPLACE_CMD} -e 's|cp $$(DESTDIR)|cp -f $$(DESTDIR)|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${RMDIR} ${STAGEDIR}${EXAMPLESDIR}/networks/autostart
	@${MKDIR} ${STAGEDIR}${ETCDIR}/qemu/networks/autostart
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.for dir in run/libvirt/network \
	run/libvirt/qemu \
	run/libvirt/lockd \
	log/libvirt/uml \
	log/libvirt/qemu \
	log/libvirt/lxc \
	lib/libvirt/boot \
	lib/libvirt/lockd/files \
	lib/libvirt/images \
	lib/libvirt/dnsmasq \
	lib/libvirt/filesystems \
	lib/libvirt/network \
	lib/libvirt/qemu/channel/target \
	cache/libvirt/qemu
	@${MKDIR} "${STAGEDIR}/${VARDIR}/${dir}"
.endfor

.for file in ${CONF_FILES}
	@if test -f ${STAGEDIR}${ETCDIR}/${file}; then \
		${MV} ${STAGEDIR}${ETCDIR}/${file} \
		${STAGEDIR}${ETCDIR}/${file}.sample; fi
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
