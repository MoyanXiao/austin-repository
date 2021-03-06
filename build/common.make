# $RCSfile: common.make,v $
# 
# Overview
#   This makefile is intended to be included in other makefiles, and sets
#   up the environment for building sources. 
#
#

#get the OS string
OS:=$(shell sh $(ROOT)/build/getos)

#
# Standard subdirectories for source, include, and binary files
#
SRCDIR=./src
INCDIR=./include

# Check to see if this is debug or release
ifndef DEBUG
WORKDIR=./release
BINDIR=./release
LIBDIR=release
else
WORKDIR=./debug
BINDIR=./debug
LIBDIR=debug
endif

#
# Standard search lists
#
vpath %.c $(SRCDIR)
vpath %.cc $(SRCDIR)
vpath %.cpp $(SRCDIR)
vpath %.cxx $(SRCDIR)
vpath %.h $(INCDIR)
vpath %.i $(WORKDIR)
vpath %.o $(WORKDIR)
vpath %.lo $(WORKDIR)

# OS-depent flag set
include $(ROOT)/build/$(OS)-include

# target dependency rule
include $(ROOT)/build/dependency-common-include

INCLUDE_DIRS :=$(INCDIR)

.PHONY: all clean debug debugclean alltarget FORCE



