# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		cmake:outsource compiler:c++11-lib
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	grzegorzmazur

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch:
#	Can't use USES=shebangfix here, cause the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e \
		's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/tests/test-yacas

do-test:
	cd ${BUILD_WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
