# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libwapcaplet
PORTVERSION=	0.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	String internment library

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:${PORTSDIR}/devel/netsurf-buildsystem \
	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USES=	gmake
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwapcaplet.so*

.include <bsd.port.mk>
