# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rugged
PORTVERSION=	0.24.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rugged is a Ruby binding to the libgit2 linkable library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake \
		libgit2>=${PORTVERSION:R}:${PORTSDIR}/devel/libgit2
LIB_DEPENDS=	libgit2.so:${PORTSDIR}/devel/libgit2

CONFIGURE_ARGS=	--use-system-libraries
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USES=		pkgconfig

.include <bsd.port.mk>
