# $FreeBSD$

PORTNAME=	qt5ct
PORTVERSION=	0.21
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 5 configuration tool

LICENSE=	BSD2CLAUSE

USES=		qmake tar:bz2
USE_QT5=	gui svg widgets buildtools_build linguisttools_build

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR} && \
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
