# Created by: Max V. Kostikov <max@kostikov.co>
# $FreeBSD$

PORTNAME=	megatools
PORTVERSION=	1.9.96
CATEGORIES=	net
MASTER_SITES=	http://megatools.megous.com/builds/

MAINTAINER=	max@kostikov.co
COMMENT=	Tools for MEGA.CO.NZ cloud drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	glib-networking>=2.32.0:${PORTSDIR}/net/glib-networking

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
USES=		gmake pathfix pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_OPENSSL=	yes

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection=no

OPTIONS_DEFINE=	FUSE
OPTIONS_DEFAULT=	FUSE
OPTIONS_SUB=	yes

FUSE_USES=	fuse
FUSE_CONFIGURE_WITH=	fuse

.include <bsd.port.mk>
