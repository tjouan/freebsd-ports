# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	Flask-Sockets
PORTVERSION=	0.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Elegant WebSockets for your Flask apps

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:${PORTSDIR}/www/py-gevent-websocket

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
