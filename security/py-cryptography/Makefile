# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cryptography
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Cryptographic recipes and primitives for Python developers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:${PORTSDIR}/devel/py-cffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.1:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.8:${PORTSDIR}/devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:${PORTSDIR}/devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}idna>=2.0:${PORTSDIR}/dns/py-idna
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:${PORTSDIR}/devel/py-iso8601

USES=		python
USE_OPENSSL=	yes
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>0:${PORTSDIR}/net/py-ipaddress
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cryptography/hazmat/bindings/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
