# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	datamodeler
PORTVERSION=	4.1.3.901
DISTVERSIONSUFFIX=-1
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html
DISTNAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}.noarch
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	oracle

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Database modeling tool

EXTRACT_DEPENDS=rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes
JAVA_VERSION=	1.8+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license
NO_CDROM=	Packaging prohibited by Oracle license

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/opt/${PORTNAME}
SUB_FILES=	${PORTNAME}.script.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	due to Oracle license restrictions, you must fetch the source \
distribution manually. Please access \
http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html \
with a web browser and follow the link for the ${DISTFILES}. You will be \
required to register and log in, but you can create an account on that \
page. After registration and accepting the Oracle License, download the \
distribution file, ${DISTFILES}, into ${DISTDIR}/${DIST_SUBDIR}/ and then \
restart this installation.
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing scripts..."
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.script.sh ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	@${ECHO_MSG} " [ DONE ]"

.for d in configuration datamodeler dropins dvt equinox external ide \
    jdbc jdev jlib modules netbeans rdbms sleepycat \
    sqldeveloper svnkit
	@${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	@cd ${WRKSRC} && ${FIND} ${d} -type d \
		-exec ${MKDIR} ${STAGEDIR}/${DATADIR}/\{} \;
	@cd ${WRKSRC} && ${FIND} ${d} -type f \
		-not -name "*.orig" \
		-not -name "*.exe" \
		-not -name "*.bat" \
		-not -name "*.bak" \
		-not -name "*.dll" \
		-exec ${INSTALL_DATA} \{} ${STAGEDIR}/${DATADIR}/\{} \;
	@${ECHO_MSG} " [ DONE ]"
.endfor

	@${ECHO_MSG} -n ">> Installing icon ..."
	@${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}/${DATADIR}/icon.png
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
