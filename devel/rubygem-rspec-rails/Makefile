# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-rails
PORTVERSION=	3.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.md

RUN_DEPENDS=	rubygem-actionpack4>=3.0:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-activesupport4>=3.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-railties4>=3.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-rspec-core>=${PORTVERSION:R}.0:${PORTSDIR}/devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}.0:${PORTSDIR}/devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}.0:${PORTSDIR}/devel/rubygem-rspec-mocks \
		rubygem-rspec-support>=${PORTVERSION:R}.0:${PORTSDIR}/devel/rubygem-rspec-support

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
