# Created by: mat@FreeBSD.org
# $FreeBSD$

PORTNAME=	epp-client-afnic
PORTVERSION=	0.15.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mat@FreeBSD.org
COMMENT=	AFNIC EPP client library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
		rubygem-nokogiri>=1.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-epp-client-base=${PORTVERSION}:${PORTSDIR}/net/rubygem-epp-client-base \
		rubygem-epp-client-rgp=${PORTVERSION}:${PORTSDIR}/net/rubygem-epp-client-rgp \
		rubygem-epp-client-secdns=${PORTVERSION}:${PORTSDIR}/net/rubygem-epp-client-secdns \

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
