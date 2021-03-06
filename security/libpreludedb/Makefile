# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	1.0.1p1
PORTREVISION=	10
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/287/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for access to Prelude NIDS database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl \
		libgmp.so:${PORTSDIR}/math/gmp \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libprelude.so:${PORTSDIR}/security/libprelude \
		libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit

USES=		gettext gmake iconv libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no \
		--with-html-dir=${PREFIX}/share/doc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS PERL PYTHON
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=		yes

MYSQL_DESC=		MySQL plugin
MYSQL_USE=		mysql=yes
MYSQL_CONFIGURE_WITH=	mysql
PERL_DESC=		Perl bindings
PERL_USES=		perl5
PERL_USE=		perl5=build,run
PERL_CONFIGURE_WITH=	perl
PGSQL_DESC=		PostgreSQL plugin
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql
PYTHON_USES=		python
PYTHON_CONFIGURE_WITH=	python
PYTHON_PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"
SQLITE_DESC=		SQLite3 plugin
SQLITE_USE=		sqlite=yes
SQLITE_CONFIGURE_WITH=	sqlite3

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* \
		${STAGEDIR}${DOCSDIR}

post-install-PERL-on:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/perl5 \
		-name "*.so" | ${XARGS} ${STRIP_CMD}

post-install-PYTHON-on:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
