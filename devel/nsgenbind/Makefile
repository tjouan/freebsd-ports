# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	nsgenbind
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	NetSurf Generator for JavaScript bindings

LICENSE=	MIT

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:${PORTSDIR}/devel/netsurf-buildsystem \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USES=	bison gmake

WRKSRC=	${WRKDIR}/${DISTNAME:S/-src//}

MAKE_ENV+=	COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"

PLIST_FILES=	bin/nsgenbind

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
