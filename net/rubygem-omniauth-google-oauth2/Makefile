# $FreeBSD$

PORTNAME=	omniauth-google-oauth2
PORTVERSION=	0.4.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Google OAuth2 strategy for OmniAuth 1.x

LICENSE=	MIT

RUN_DEPENDS=	rubygem-jwt>=1.5.2:${PORTSDIR}/www/rubygem-jwt \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-omniauth>=1.1.1:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.3.1:${PORTSDIR}/net/rubygem-omniauth-oauth2

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
