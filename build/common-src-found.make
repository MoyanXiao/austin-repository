# $RCSfile: common-src-found.make,v $
# 
# Overview
#   This makefile is intended to be included in other makefiles, and obtain
#   the header and source file to be built. Common component could be set 
#   here and control by FLAG.
#
#

# define the google test/mock header/lib
ifdef GOOGLE_MOCK
INCLUDE_DIRS += ${ROOT}/google/include/
LDFLAGS +=  -lpthread
STATIC_LINK_FILES += ${ROOT}/google/lib/gmock_main${LIBEXT}
SUPPORT_LIB+=gtest${SUP_LIB}
endif

# define the google test/mock header/lib
ifdef GOOGLE_BENCHMARK
INCLUDE_DIRS += ${ROOT}/google/include/
STATIC_LINK_FILES += ${ROOT}/google/lib/${LIBPREFIX}benchmark${LIBEXT}
SUPPORT_LIB+=benchmark${SUP_LIB}
endif
# get all the source file
SOURCES:= $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.cpp)
C_SOURCES:= $(filter %.c, $(SOURCES))
CPP_SOURCES:= $(filter %.cpp, $(SOURCES))

# preCompile to inter files 
INTER:= $(foreach OBJ,$(C_SOURCES:$(SRCDIR)%.c=%$(INTER_SUFFIX)),$(BINDIR)$(OBJ))
INTER+= $(foreach OBJ,$(CPP_SOURCES:$(SRCDIR)%.cpp=%$(INTER_SUFFIX)),$(BINDIR)$(OBJ))

# get all the object files(.o) according to the source files 
OBJECTS:= $(foreach OBJ,$(C_SOURCES:$(SRCDIR)%.c=%$(OBJ_SUFFIX)),$(BINDIR)$(OBJ))
OBJECTS+= $(foreach OBJ,$(CPP_SOURCES:$(SRCDIR)%.cpp=%$(OBJ_SUFFIX)),$(BINDIR)$(OBJ))

LOBJECTS:= $(foreach OBJ,$(C_SOURCES:$(SRCDIR)%.c=%$(LOBJ_SUFFIX)),$(BINDIR)$(OBJ))
LOBJECTS+= $(foreach OBJ,$(CPP_SOURCES:$(SRCDIR)%.cpp=%$(LOBJ_SUFFIX)),$(BINDIR)$(OBJ))

DEP_OBJECTS+= $(foreach OBJ,$(OBJECTS:$(BINDIR)%$(OBJ_SUFFIX)=%$(DEP_SUFFIX)),.$(OBJ))

# set the link library by STATIC_LINK_FILES and LIBRARY_PATHS 
LDLIBS+= $(STATIC_LINK_FILES)
LDLIBS+= $(patsubst %,-L%,$(LIBRARY_PATHS))
