# $FreeBSD$

PORTNAME=	vimb-gtk3

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3

MAKE_ENV=	GTK="3"
USE_GNOME=	gtk30

CONFLICTS=	vimb-gtk2-*

MASTERDIR=	${.CURDIR}/../vimb-gtk2

DESCR=		${MASTERDIR}/pkg-descr
DISTINFO_FILE=	${MASTERDIR}/distinfo
PKGMESSAGE=	${MASTERDIR}/pkg-message
FILESDIR=	${MASTERDIR}/files

.include "${MASTERDIR}/Makefile"
