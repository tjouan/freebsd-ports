# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	passlib
PORTVERSION=	1.6.5
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python password hashing framework supporting over 30 schemes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.1:${PORTSDIR}/devel/py-nose

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# A number of (bcrypt) tests are failing due to:
# AssertionError: sanity check failed: 'os_crypt' backend supports $2b$ but has wraparound bug
# See:
#   WRKSRC/passlib/handlers/bcrypt.py#306
#   http://www.openwall.com/lists/oss-security/2012/01/02/4

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
