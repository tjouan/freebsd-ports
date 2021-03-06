# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmex
PORTVERSION=	1.2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	finance
MASTER_SITES=	https://github.com/vslavik/bakefile/releases/download/v0.2.9/:bakefile \
		SF/wxcode/Components/wxSQLite3:wxsqlite3
DISTFILES=	bakefile-0.2.9${EXTRACT_SUFX}:bakefile \
		${WXSQLITE3_DISTNAME}${EXTRACT_SUFX}:wxsqlite3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open-source, easy-to-use personal finance software

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	moneymanagerex
GH_PROJECT=	moneymanagerex

WXSQLITE3_DISTNAME=	wxsqlite3-3.2.1

GH_TUPLE=	Regaddi:Chart.js:f13f99b:chart_js \
		FVANCOP:ChartNew.js:77e7f87:chartnew_js \
		diepes:sorttable.js:3c63cb0:sorttable_js \
		moneymanagerex:database:5d7129f:database \
		moneymanagerex:LuaGlue:c51d11a:luaglue \
		moneymanagerex:cajun:3684900:cajun \
		moneymanagerex:html-template:cd434ee:html_template \
		moneymanagerex:csv-parser:ca3f0d7:csv_parser \
		moneymanagerex:ctpp:20158e0:ctpp \
		moneymanagerex:mongoose:97583a6:mongoose

USES=		autoreconf compiler:c++11-lib gettext gmake
GNU_CONFIGURE=	yes
USE_WX=		3.0
WX_CONF_ARGS=	absolute
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-DHAVE_ACOSH \
		-DHAVE_ASINH \
		-DHAVE_ATANH \
		-DHAVE_ISBLANK \
		-DSQLITE_USER_AUTHENTICATION=0
LDFLAGS+=	-L${LOCALBASE}/lib
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs
LDFLAGS+=	-lboost_system
.endif

post-extract:
	@${MV} ${WRKSRC_database}/* ${WRKSRC}/database
	@${MV} ${WRKSRC_chart_js}/* ${WRKSRC}/3rd/Chart.js
	@${MV} ${WRKSRC_chartnew_js}/* ${WRKSRC}/3rd/ChartNew.js
	@${MV} ${WRKSRC_luaglue}/* ${WRKSRC}/3rd/LuaGlue
	@${MV} ${WRKSRC_cajun}/* ${WRKSRC}/3rd/cajun
	@${MV} ${WRKSRC_csv_parser}/* ${WRKSRC}/3rd/csv-parser
	@${MV} ${WRKSRC_ctpp}/* ${WRKSRC}/3rd/ctpp
	@${MV} ${WRKSRC_html_template}/* ${WRKSRC}/3rd/cgitemplate
	@${MV} ${WRKSRC_mongoose}/* ${WRKSRC}/3rd/mongoose
	@${MV} ${WRKSRC_sorttable_js}/* ${WRKSRC}/3rd/sorttable.js
	@${MV} ${WRKDIR}/${WXSQLITE3_DISTNAME}/* ${WRKSRC}/lib/wxsqlite3
	@${MV} ${WRKDIR}/bakefile-0.2.9/autoconf/*.m4 ${WRKSRC}/m4

post-patch:
	@${REINPLACE_CMD} -e \
		's|\*.txt|contrib.txt version.txt| ; \
		 s|$$(datadir)/man|$$(prefix)/man| ; \
		 s|-ldl$$||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^AC_INIT/s|1.2.3|${PORTVERSION}| ; \
		 s|\[noext\]|[]|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's| -g0 -O2||' ${WRKSRC}/m4/wxpresets.m4

.include <bsd.port.post.mk>
