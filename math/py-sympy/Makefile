# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	sympy
PORTVERSION=	1.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library For Symbolic Mathematics

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	PYGLET
PYGLET_DESC=	Enable plotting support

PYGLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet

post-patch:
	@${REINPLACE_CMD} -e "s#share/man/man1#man/man1#" ${WRKSRC}/setup.py

.include <bsd.port.mk>
