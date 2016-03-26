# $FreeBSD$

PORTNAME=	opentx
PORTVERSION=	2.1.7
CATEGORIES=	comms

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Custom firmware for Transmitters

LICENSE=	GPLv2

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		xsdcxx:${PORTSDIR}/devel/xsd \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui
LIB_DEPENDS=	libxerces-c.so:${PORTSDIR}/textproc/xerces-c3

USES=		cmake:outsource gmake
USE_GITHUB=	yes
USE_QT4=	qmake_build linguisttools_build moc_build rcc_build uic_build \
		gui network xml
CMAKE_SOURCE_PATH=	${WRKSRC}/companion/src

PLIST_FILES=	%%QT_BINDIR%%/companion

.include <bsd.port.mk>
