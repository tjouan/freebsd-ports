# $FreeBSD$

PORTNAME=	rubocop
PORTVERSION=	0.38.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code style checking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-parser>=2.3.0.6:${PORTSDIR}/devel/rubygem-parser \
		rubygem-powerpack>=0.1:${PORTSDIR}/devel/rubygem-powerpack \
		rubygem-rainbow>=1.99.1:${PORTSDIR}/devel/rubygem-rainbow \
		rubygem-ruby-progressbar>=1.7:${PORTSDIR}/devel/rubygem-ruby-progressbar \
		rubygem-unicode-display_width>=1.0.1:${PORTSDIR}/devel/rubygem-unicode-display_width

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rubocop

.include <bsd.port.mk>
