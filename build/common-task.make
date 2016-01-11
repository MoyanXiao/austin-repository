# $RCSfile: common-src-found.make,v $
# 
# Overview
#   This makefile is intended to be included in other makefiles, and
#   generate the make target.
#

all: alltarget

alltarget: ${SUPPORT_LIB} $(DEP_OBJECTS) $(TARGET) 

clean:
	-$(RM) $(TARGET)
	-$(RM) $(INTER)
	-$(RM) $(OBJECTS)
	-$(RM) $(LOBJECTS)
	-$(RM) $(DEP_OBJECTS)

$(TARGET): $(INTER) $(OBJECTS) $(LOBJECTS) FORCE

debug:
	$(MAKE) all "DEBUG=-g";

debugclean:
	$(MAKE) clean "DEBUG=-g"
