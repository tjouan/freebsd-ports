# $FreeBSD$

PORTNAME=	uh-wm
PORTVERSION=	0.0.15
CATEGORIES=	x11-wm rubygems
MASTER_SITES=	RG

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Minimalistic tiling and stacking window manager for X.

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-uh>=2.0.2:${PORTSDIR}/x11-toolkits/rubygem-uh \
		rubygem-uh-layout>=0.4.2:${PORTSDIR}/x11-wm/uh-layout \
		rubygem-rb-kqueue>=0.2.4:${PORTSDIR}/devel/rubygem-rb-kqueue

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/uhwm

.include <bsd.port.mk>
