# Created by: Quentin Stievenart <acieroid@awesom.eu>
# $FreeBSD$

PORTNAME=	zathura
PORTVERSION=	0.3.4
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/projects/zathura/download/

MAINTAINER=	quentin.stievenart@gmail.com
COMMENT=	Customizable lightweight pdf viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libgirara-gtk3.so:${PORTSDIR}/x11-toolkits/girara
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils

USE_GNOME=	glib20 gtk30
USES=		compiler:c11 gmake pkgconfig
MAKE_ENV=	SFLAGS="${STRIP}" \
		RSTTOMAN=${LOCALBASE}/bin/rst2man \
		ZLIB_INC= \
		ZLIB_LIB=-lz

OPTIONS_DEFINE=	NLS SQLITE
OPTIONS_SUB=	yes

SQLITE_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
SQLITE_MAKE_ENV=	WITH_SQLITE=1
SQLITE_MAKE_ENV_OFF=	WITH_SQLITE=0
NLS_USES=		gettext

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|man[15]|man/&|g' \
		-e 's|$${LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g'\
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|PLUGINDIR ?= .*$$|PLUGINDIR ?= ${PREFIX}/lib/zathura|'\
		${WRKSRC}/config.mk
	${REINPLACE_CMD} -e '/^CC  /d'\
		${WRKSRC}/colors.mk
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		-e 's/-lc//' \
		-e 's/DL_LIB /#&/' \
		${WRKSRC}/config.mk
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/zathura/config.h \
		${WRKSRC}/doc/man/zathurarc.5.rst
	(cd ${WRKSRC}; ${RM} -f zathura.1 zathurarc.5)

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e '/-C po/d'\
		${WRKSRC}/Makefile

.include <bsd.port.mk>
