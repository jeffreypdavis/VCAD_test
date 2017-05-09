#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Test_2D.o \
	${OBJECTDIR}/Test_2D3D.o \
	${OBJECTDIR}/Test_3D.o \
	${OBJECTDIR}/Test_3D_Intersect.o \
	${OBJECTDIR}/Test_STL.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../VCAD_lib/dist/Debug/GNU-Linux -Wl,-rpath,'../VCAD_lib/dist/Debug/GNU-Linux' -Wl,-rpath,'../VCAD_lib/dist/Debug/GNU-Linux' -L../VCAD_lib/dist/Debug/GNU-Linux -lVCAD_lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vcad_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vcad_test: ../VCAD_lib/dist/Debug/GNU-Linux/libVCAD_lib.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vcad_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vcad_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Test_2D.o: Test_2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Test_2D.o Test_2D.cpp

${OBJECTDIR}/Test_2D3D.o: Test_2D3D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Test_2D3D.o Test_2D3D.cpp

${OBJECTDIR}/Test_3D.o: Test_3D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Test_3D.o Test_3D.cpp

${OBJECTDIR}/Test_3D_Intersect.o: Test_3D_Intersect.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Test_3D_Intersect.o Test_3D_Intersect.cpp

${OBJECTDIR}/Test_STL.o: Test_STL.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Test_STL.o Test_STL.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../VCAD_lib -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../VCAD_lib && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libVCAD_lib.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vcad_test

# Subprojects
.clean-subprojects:
	cd ../VCAD_lib && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
