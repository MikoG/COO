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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/biome_default.o \
	${OBJECTDIR}/biome_hills.o \
	${OBJECTDIR}/biome_land_mass.o \
	${OBJECTDIR}/clickmode_panel.o \
	${OBJECTDIR}/debug_pane.o \
	${OBJECTDIR}/game.o \
	${OBJECTDIR}/game_menu.o \
	${OBJECTDIR}/loading_screen.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/main_menu.o \
	${OBJECTDIR}/mission_planner.o \
	${OBJECTDIR}/pause_menu.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m32
CXXFLAGS=-m32

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../SID/dist/Debug/GNU-Linux-x86 -Wl,-rpath,../SID/dist/Debug/GNU-Linux-x86 -lSID `pkg-config --libs sdl2` `pkg-config --libs SDL2_mixer` `pkg-config --libs SDL2_image` `pkg-config --libs gl` `pkg-config --libs glu`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coo

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coo: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coo ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/biome_default.o: biome_default.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/biome_default.o biome_default.cpp

${OBJECTDIR}/biome_hills.o: biome_hills.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/biome_hills.o biome_hills.cpp

${OBJECTDIR}/biome_land_mass.o: biome_land_mass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/biome_land_mass.o biome_land_mass.cpp

${OBJECTDIR}/clickmode_panel.o: clickmode_panel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clickmode_panel.o clickmode_panel.cpp

${OBJECTDIR}/debug_pane.o: debug_pane.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/debug_pane.o debug_pane.cpp

${OBJECTDIR}/game.o: game.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/game.o game.cpp

${OBJECTDIR}/game_menu.o: game_menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/game_menu.o game_menu.cpp

${OBJECTDIR}/loading_screen.o: loading_screen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/loading_screen.o loading_screen.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/main_menu.o: main_menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_menu.o main_menu.cpp

${OBJECTDIR}/mission_planner.o: mission_planner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mission_planner.o mission_planner.cpp

${OBJECTDIR}/pause_menu.o: pause_menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -DDEBUG `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_mixer` `pkg-config --cflags SDL2_image` `pkg-config --cflags gl` `pkg-config --cflags glu` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pause_menu.o pause_menu.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/coo

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
