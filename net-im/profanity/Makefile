# $FreeBSD$

PORTNAME=	profanity
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.profanity.im/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Console based XMPP client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libstrophe.so:${PORTSDIR}/net-im/libstrophe \
		libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libotr.so.5:${PORTSDIR}/security/libotr \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libgpgme.so:${PORTSDIR}/security/gpgme

USES=		ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-otr
CONFIGURE_ENV=	LIBS="${CFLAGS} -lcrypto"

OPTIONS_DEFINE=	NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notifications

.include <bsd.port.mk>
