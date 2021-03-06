# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_http2-devel
PORTVERSION=	1.2.8
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Early experience HTTP/2 module for Apache httpd

LICENSE=	APACHE20

BUILD_DEPENDS=	nghttp2>=1.2:${PORTSDIR}/www/nghttp2
LIB_DEPENDS=	libnghttp2.so:${PORTSDIR}/www/nghttp2

USE_GITHUB=	yes
GH_ACCOUNT=	icing
GH_PROJECT=	mod_h2

USES=		autoreconf libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=ext-
CONFIGURE_ENV=	CONFIG_SHELL=/bin/sh

USE_APACHE=	24
MODULENAME=	${GH_PROJECT}

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	# Rename mod_http2 to mod_h2 to avoid conflict with Apache24
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_http2.so
	${MV} ${STAGEDIR}${PORTDOCS}${PREFIX}/share/doc/mod_http2 \
		${STAGEDIR}${PORTDOCS}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.mk>
