# $FreeBSD$

PORTNAME=	libuecc
PORTVERSION=	6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://git.universe-factory.net/libuecc/snapshot/

MAINTAINER=	crest_maintainer@rlwinm.de
COMMENT=	Very small Elliptic Curve Cryptography library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

USE_LDCONFIG=	yes

USES=		cmake:outsource pkgconfig tar

.include <bsd.port.mk>
