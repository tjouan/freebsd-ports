# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CoinMP
PORTVERSION=	1.8.3
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/

MAINTAINER=	cpm@fbsd.es
COMMENT=	Optimization library with support for COIN-OR CLP, CBC, and CGL

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# note: with ogdf only if build with COIN option
CONFLICTS=	clp-[0-9]* ogdf-*

GNU_CONFIGURE=	yes
USES=	libtool pkgconfig tar:tgz
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig
CXXFLAGS+=	-ffast-math

OPTIONS_DEFINE=	DEBUG DOCS GLPK

GLPK_DESC=	GNU Linear Programming Kit support

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLPK}
CONFIGURE_ARGS+=	--with-gmpl-incdir=${LOCALBASE}/include	\
		--with-gmpl-lib="-L${LOCALBASE}/lib -lglpk"
LIB_DEPENDS+=	libglpk.so:${PORTSDIR}/math/glpk
.else
CONFIGURE_ARGS+=	--disable-glpk-libcheck
.endif

.if ${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=	-fomit-frame-pointer
.endif

STRIP_FILES=	libCoinUtils libOsi libOsiClp libOsiCommonTests libClp libClpSolver \
		libCgl libCbc libCbcSolver libOsiCbc libCoinMP

post-patch::
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		-e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g' \
		-e 's|addlibs_DATA = examples/Makefile examples/example.c||g' \
		-e 's|DocInstallDir = $$(datadir)/coin/doc/$$(PACKAGE_NAME)|DocInstallDir = $$(datadir)/doc/CoinMP/$$(PACKAGE_NAME)|' \
		-e 's|	$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook||'
	${REINPLACE_CMD} -e 's|datacoin_DATA = $$(EXAMPLE_FILES)|datacoin_DATA = |' \
		-e 's|datacoindir = $$(datadir)/coin/Data/Sample|datacoindir = |' ${WRKSRC}/Data/Sample/Makefile.in
	${REINPLACE_CMD} -e 's|addlibsdir = $$(DESTDIR)$$(datadir)/coin/doc/CoinMP|addlibsdir = |' ${WRKSRC}/CoinMP/Makefile.in

post-install:
.for filename in ${STRIP_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${filename}.so.*
.endfor

check regression-test test: build
	${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} test -C ${WRKSRC}

.include <bsd.port.mk>
