# Makefile
# $Id$
#MIDASSYS=/home/olchansk/daq/midas/midas

OSFLAGS  =  -DOS_LINUX -Dextname
CFLAGS   =  -g -O2 -Wall -Wuninitialized -I$(INC_DIR) -I$(DRV_DIR) -I$(VMICHOME)/include -I$(MIDASSYS)/include -I$(MIDASSYS)/drivers/ -I$(MIDASSYS)/drivers/vme -I$(MIDASSYS)/drivers/vme/vmic -I/home/lindner/packages/vmisft-7433-3.6-KO5/vme_universe/include
CXXFLAGS = $(CFLAGS) -DHAVE_ROOT -DUSE_ROOT -I$(ROOTSYS)/include

LIBS = -lm -lz -lutil -lnsl -lpthread -lrt

DRV_DIR         = $(MIDASSYS)/drivers
INC_DIR         = $(MIDASSYS)/include
LIB_DIR         = $(MIDASSYS)/linux/lib


# MIDAS library
MIDASLIBS = $(LIB_DIR)/libmidas.a

# ROOT library
ROOTLIBS = $(shell $(ROOTSYS)/bin/root-config --libs) -lThread -Wl,-rpath,$(ROOTSYS)/lib

all: fev785.exe 

gefvme.o: $(MIDASSYS)/drivers/vme/vmic/gefvme.c
	gcc -c -o $@ -O2 -g -Wall -Wuninitialized $(CFLAGS) $< 

vmicvme.o: $(MIDASSYS)/drivers/vme/vmic/vmicvme.c
	gcc -c -o $@ -O2 -g -Wall -Wuninitialized $(CFLAGS) $<

%.o: $(MIDASSYS)/drivers/vme/%.c
	gcc -c -o $@ -O2 -g -Wall -Wuninitialized $(CFLAGS) $< 

fev785.exe: $(MIDASLIBS) $(LIB_DIR)/mfe.o fev785.o gefvme.o   v792.o v1190B.o 
	$(CXX) -o $@ $(CFLAGS) $(OSFLAGS) $^ $(MIDASLIBS)   $(LIBS) $(CFLAGS) # -lvme


%.o: %.c
	$(CC) $(CFLAGS) $(OSFLAGS) $(CFLAGS)  -c $<

%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(OSFLAGS) -c $<

clean::
	-rm -f *.o *.exe

# end
