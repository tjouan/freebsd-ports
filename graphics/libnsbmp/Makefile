# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libnsbmp
PORTVERSION=	0.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	NetSurf BMP decoder

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:${PORTSDIR}/devel/netsurf-buildsystem

USES=	gmake
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared"

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnsbmp.so*

.include <bsd.port.mk>
