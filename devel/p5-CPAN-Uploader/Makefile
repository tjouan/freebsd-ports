# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	CPAN-Uploader
PORTVERSION=	0.103004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Upload things to the CPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Getopt-Long-Descriptive>=0.084:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
