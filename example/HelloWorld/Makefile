# 1 --> set the ROOT micro and build sripts directory
ifndef ROOT
ROOT=../..
unexport ROOT
endif
BUILD_SCR=${ROOT}/build

# 2 --> include the common.make file for environment setting and build dependency 
include ${BUILD_SCR}/common.make

# 3 --> add extra header search path
# INCLUDE_DIRS += ....

# 4 --> add extra library file or path
# STATIC_LINK_FILES += ...
# LIBRARY_PATHS += ...

# 5 --> set the TARGET file
TARGET=${BINDIR}/HelloWorld${EXEEXT}


# 6 --> include .make for source file searching and target building 
include ${BUILD_SCR}/common-src-found.make
include ${BUILD_SCR}/common-task.make
