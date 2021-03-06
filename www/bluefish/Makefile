# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	2.2.8
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libenchant.so:${PORTSDIR}/textproc/enchant

USES=		desktop-file-utils gettext gmake libtool pkgconfig python \
		shared-mime-info tar:bzip2
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG DOCS TIDY WEBLINT
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2 WEBLINT
OPTIONS_SUB=	yes

TOOLKIT_DESC=		GTK+ toolkit
WEBLINT_DESC=		Weblint HTML checker support

DEBUG_CONFIGURE_ENABLE=	debugging-output
GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ON=	--with-gtk2=yes
GTK2_CONFIGURE_OFF=	--with-gtk2=no
GTK3_LIB_DEPENDS=	libgucharmap_2_90.so:${PORTSDIR}/deskutils/gucharmap
GTK3_USE=		gnome=gtk30
TIDY_RUN_DEPENDS=	tidy4:${PORTSDIR}/www/tidy
WEBLINT_RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

.include <bsd.port.mk>
