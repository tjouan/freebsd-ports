# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubyrep
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ltning@anduin.net
COMMENT=	Multi-master replication and sync for MySQL and PostgreSQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord
RUN_DEPENDS=	flog>=0:${PORTSDIR}/sysutils/flog \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		shebangfix
SHEBANG_FILES=	bin/rubyrep rubyrep

USE_RC_SUBR=	rubyrep

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=PGSQL

PLIST_FILES=	bin/rubyrep

PGSQL_RUN_DEPENDS=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
MYSQL_RUN_DEPENDS=	ruby-mysql>=0:${PORTSDIR}/databases/ruby-mysql

.include <bsd.port.mk>
