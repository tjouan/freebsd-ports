# Created by: David Chisnall <theraven@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cheritrace
PORTVERSION=	0.0.1
CATEGORIES=	devel security

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Library and tool for interacting with CHERI streamtraces.

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	a7ddf11

BUILD_DEPENDS+=	llvm-config-cheri:${PORTSDIR}/devel/llvm-cheri
LIB_DEPENDS+=	libLLVMCore.so:${PORTSDIR}/devel/llvm-cheri

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config-cheri

.include <bsd.port.mk>
