# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	20140622%2Bbzr4027
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://launchpadlibrarian.net/179199115/
DISTNAME=	${PORTNAME}_0.${DISTVERSION}.orig

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf

CONFLICTS=	kicad-devel*

USES=		cmake desktop-file-utils dos2unix shared-mime-info tar:xz

# Does not compile with Gcc48
USE_GCC=	4.7
#USES+=		compiler:gcc-c++11-lib
LDFLAGS+=	-L${LOCALBASE}/lib/c++
CXXFLAGS+=	-nostdinc++ -isystem ${LOCALBASE}/include/c++/v1
BUILD_DEPENDS+=	${LOCALBASE}/lib/c++/libstdc++.so:${PORTSDIR}/devel/libc++
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

DOS2UNIX_GLOB=	*.cmake sch_bus_entry.h sch_line.h sch_no_connect.h
USE_XORG=	ice x11 xext
USE_GL=		yes
USE_WX=		3.0
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
CXXFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include -DBOOST_HASH_NO_EXTENSIONS
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}	\
		-DwxUSE_UNICODE=ON -DKICAD_STABLE_VERSION=ON	\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-0.${DISTVERSION:C/%2B/+/}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

# undefined reference to `std::chrono::_V2::steady_clock::now()@GLIBCXX_3.4.19'
BROKEN_FreeBSD_9=	does not link

DOCS_VARS=	LICENSE+=GFDL LICENSE_COMB=multi

post-patch:
	${MV} ${WRKSRC}/include/boost ${WRKSRC}/include/boost.orig

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/evince|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/kpdf|${LOCALBASE}/bin/okular|'		\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		-e 's|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|'	\
		${WRKSRC}/common/gestfich.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/library && ${COPYTREE_SHARE} library ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/library && ${COPYTREE_SHARE} modules ${STAGEDIR}${DATADIR})

post-install-NLS-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/internat
	(cd ${WRKSRC}/doc/internat &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/internat)
	${RM} -f ${STAGEDIR}${DATADIR}/internat/CMakeLists.txt
	${FIND} ${STAGEDIR}${DATADIR}/internat -name kicad.po -delete

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
