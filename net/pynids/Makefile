# Created by: Corey Smith
# $FreeBSD$

PORTNAME=	pynids
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://jon.oberheide.org/pynids/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	corsmith@gmail.com
COMMENT=	Python interface to libnids

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

USES=		pkgconfig python
USE_GNOME=	glib20
USE_PYTHON=	distutils autoplist pythonprefix

post-extract:
	@cd ${WRKSRC} && ${TAR} xzf libnids-1.24.tar.gz

post-patch:
	@${CP} -f ${TEMPLATES}/config.guess ${WRKSRC}
	@${CHMOD} a+rx ${WRKSRC}/config.guess
	@${CP} -f ${TEMPLATES}/config.sub ${WRKSRC}
	@${CHMOD} a+rx ${WRKSRC}/config.sub
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
