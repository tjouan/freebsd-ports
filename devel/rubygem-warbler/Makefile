# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	warbler
PORTVERSION=	1.4.9
PORTREVISION=	1
CATEGORIES=	devel rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Constructor of .war files of Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby \
		rubygem-jruby-jars>=1.5.6:${PORTSDIR}/devel/rubygem-jruby-jars \
		rubygem-jruby-rack>=1.1.1:${PORTSDIR}/www/rubygem-jruby-rack \
		rubygem-rake>=0.9.6:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rubyzip>=0.9:${PORTSDIR}/archivers/rubygem-rubyzip

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/warble

.include <bsd.port.mk>
