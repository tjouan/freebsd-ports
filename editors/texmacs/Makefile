# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	texmacs
PORTVERSION=	1.99.4
PORTREVISION=	1
CATEGORIES=	editors print
MASTER_SITES=	http://www.texmacs.org/Download/ftp/tmftp/source/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG scientific text editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

USES=		cpe desktop-file-utils gmake iconv pkgconfig python \
		shared-mime-info shebangfix
USE_TEX=	tex:run dvipsk:run
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}"
MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:tu}

SHEBANG_FILES=	plugins/asymptote/bin/* plugins/dratex/bin/* \
		plugins/eukleides/bin/* plugins/feynmf/bin/* \
		plugins/mupad/bin/* plugins/texgraph/bin/* \
		plugins/xypic/bin/*

DATADIR=	${PREFIX}/share/TeXmacs

OPTIONS_DEFINE=	ASPELL FREETYPE GHOSTSCRIPT IMLIB2 PDF QT4 SQLITE
OPTIONS_DEFAULT=ASPELL FREETYPE GHOSTSCRIPT IMLIB2 PDF QT4 SQLITE
OPTIONS_SUB=	yes

ASPELL_RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_CONFIGURE_ENV_OFF=	FREETYPE_CFLAGS=" " FREETYPE_LDFLAGS=" " \
				ac_cv_header_ft2build_h=no
GHOSTSCRIPT_USES=	ghostscript:x11
GHOSTSCRIPT_CONFIGURE_ON=	--with-gs=yes
GHOSTSCRIPT_CONFIGURE_OFF=	--with-gs=no
IMLIB2_LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2
IMLIB2_CONFIGURE_WITH=	imlib2
PDF_CONFIGURE_ENABLE=	pdf-renderer
PDF_LDFLAGS=		-lz
PDF_IMPLIES=		FREETYPE GHOSTSCRIPT
QT4_USE=		qt4=accessible,gui,imageformats \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_USE_OFF=		xorg=xext
QT4_CONFIGURE_ON=	--with-qt=${QT_PREFIX} --enable-qtpipes
QT4_CONFIGURE_OFF=	--disable-qt
QT4_VARS=		QT_PLUGINS_LIST="accessible imageformats"
QT4_VARS_OFF=		QT_PLUGINS_LIST=""
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite3

post-patch:
	@${REINPLACE_CMD} -e \
		'/SVNREV\//s|^|#| ; \
		 s|/-liconv} -liconv|}| ; \
		 s|"-Wl,-rpath,"|""| ; \
		 s|\[\[ |[ |g ; \
		 s| \]\]| ]|g ; \
		 s|== no|= no| ; \
		 s|$${QT_PLUGINS_LIST/,/ }|${QT_PLUGINS_LIST}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		 '/require/s|"python"|"${PYTHON_CMD:T}"|' \
		${WRKSRC}/plugins/python/progs/init-python.scm
	@${REINPLACE_CMD} -e \
		 's|int tab=.*)|int tab)|' \
		${WRKSRC}/src/Kernel/Types/tree.hpp
	@${REINPLACE_CMD} -e \
		 's|int dpi=.*)|int dpi)|' \
		${WRKSRC}/src/Typeset/boxes.hpp

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} -name "._*" -delete
	@${FIND} ${STAGEDIR}${DATADIR} -name "*.bak" -delete
.for f in realpath texmacs.bin tm_axiom tm_graphviz tm_maple_5 tm_r tm_shell
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/TeXmacs/bin/${f}
.endfor

.include <bsd.port.mk>
