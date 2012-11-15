# $RCSfile: common-src-found.make,v $
# 
# Overview
#   This makefile is intended to be included in other makefiles, and obtain
#   the header and source file to be built. Common component could be set 
#   here and control by FLAG.
#
#


# get all the source file
SOURCES:= $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.cpp)
C_SOURCES:= $(filter %.c, $(SOURCES))
CPP_SOURCES:= $(filter %.cpp, $(SOURCES))


# get all the object files(.o) according to the source files 
OBJECTS:= $(foreach OBJ,$(C_SOURCES:$(SRCDIR)%.c=%$(OBJ_SUFFIX)),$(BINDIR)$(OBJ))
OBJECTS+= $(foreach OBJ,$(CPP_SOURCES:$(SRCDIR)%.cpp=%$(OBJ_SUFFIX)),$(BINDIR)$(OBJ))

LOBJECTS:= $(foreach OBJ,$(C_SOURCES:$(SRCDIR)%.c=%$(LOBJ_SUFFIX)),$(BINDIR)$(OBJ))
LOBJECTS+= $(foreach OBJ,$(CPP_SOURCES:$(SRCDIR)%.cpp=%$(LOBJ_SUFFIX)),$(BINDIR)$(OBJ))

DEP_OBJECTS+= $(foreach OBJ,$(OBJECTS:$(BINDIR)%$(OBJ_SUFFIX)=%$(DEP_SUFFIX)),.$(OBJ))

# set the link library by STATIC_LINK_FILES and LIBRARY_PATHS 
LDLIBS+= $(STATIC_LINK_FILES)
LDLIBS+= $(patsubst %,-L%,$(LIBRARY_PATHS))
