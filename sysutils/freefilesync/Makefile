# $FreeBSD$

PORTNAME=	freefilesync
PORTVERSION=	7.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.freefilesync.org/download/2o5osm21vcjbobv/ \
		http://www.freefilesync.org/archive/
DISTNAME=	FreeFileSync_${PORTVERSION}_Source

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Backup software to synchronize files and folders

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/zenxml/xml.h:${PORTSDIR}/textproc/zenxml
LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libnotify.so:${PORTSDIR}/devel/libnotify

WRKSRC=		${WRKDIR}/FreeFileSync/Source
DOS2UNIX_WRKSRC=${WRKDIR}
DOS2UNIX_GLOB=	*.cpp *.h

USES=		compiler:c++14-lang dos2unix gmake pkgconfig zip
USE_LDCONFIG=	yes
USE_WX=		3.0+

post-patch:
	@${REINPLACE_CMD} -e 's/wx-config/$${WX_CONFIG:T}/' \
		-e 's,g++,$${CXX},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<sys/vfs.h>|<sys/mount.h>|' \
		${WRKDIR}/zen/file_access.cpp
	@${REINPLACE_CMD} -e 's|WEXITSTATUS||' ${WRKDIR}/zen/shell_execute.h
	@${REINPLACE_CMD} -e 's|CLOCK_MONOTONIC_RAW|CLOCK_MONOTONIC|' \
		${WRKDIR}/zen/tick_count.h

.include <bsd.port.mk>
