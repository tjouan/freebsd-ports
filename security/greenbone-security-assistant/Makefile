# $FreeBSD$

PORTNAME=	greenbone-security-assistant
PORTVERSION=	6.0.10
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2299/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS web interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libopenvas_base.so:${PORTSDIR}/security/openvas-libraries \
		libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd

USES=		cmake:outsource gettext gnome pkgconfig
USE_GNOME=	glib20 libxml2 libxslt
USE_RC_SUBR=	gsad

.include <bsd.port.mk>
