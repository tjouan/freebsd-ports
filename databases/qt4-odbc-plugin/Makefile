# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2

DB=		odbc
COMMENT=	Qt Open Database Connectivity plugin

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

LDFLAGS+=	-lodbc

.include "${.CURDIR:H:H}/devel/qt4/Makefile.sqldrivers"
