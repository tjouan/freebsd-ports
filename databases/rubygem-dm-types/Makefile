# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dm-types
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin providing extra data types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-dm-core>=1.2.0:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-fastercsv>=1.5:${PORTSDIR}/devel/rubygem-fastercsv \
		rubygem-json>=1.6:${PORTSDIR}/devel/rubygem-json \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-stringex>=1.4:${PORTSDIR}/devel/rubygem-stringex \
		rubygem-uuidtools>=2.1:${PORTSDIR}/devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
