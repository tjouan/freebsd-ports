# Created by: Jeffrey Baitis <jeff@baitis.net>
# $FreeBSD$

PORTNAME=	sdr-wspr
PORTVERSION=	0.1.0
CATEGORIES=	comms hamradio

MAINTAINER=	jeff@baitis.net
COMMENT=	WSPR receiver/decoder using libsdr

LICENSE=	GPLv3

LIB_DEPENDS=	libsdr-gui.so:${PORTSDIR}/comms/libsdr-gui

USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek
GH_PROJECT=	sdr-wspr
GH_TAGNAME=	2dc1452
USE_QT5=	core buildtools_build qmake widgets
USES=		cmake:outsource compiler:gcc-c++11-lib fortran pkgconfig

PLIST_FILES=	bin/sdr-wspr share/applications/sdr-wspr.desktop \
		share/icons/sdr-wspr.svg

.include <bsd.port.mk>
