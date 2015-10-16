# =============================== 
# Makefile for MiniBonzai ZJets Analysis 
# =============================== 

HOST = $(shell hostname | grep lxplus)

ifeq ($(HOST),)
  HOST = $(shell hostname | grep iihe)
  ifeq ($(HOST),)
  else
    HOST = "iihe"
  endif
else
  HOST = "lxplus"
endif


ifeq ($(HOST), "lxplus")
  LHAPDFPATH = /afs/cern.ch/cms/slc5_amd64_gcc434/external/lhapdf/5.8.5/
else
  ifeq ($(HOST), "iihe")
    LHAPDFPATH = /user/aleonard/LHAPDF/
  endif
endif


ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags) 

LIB = RooUnfold LHAPDF
LIBLIST = $(addprefix -l, $(LIB))

LIBDIR = RooUnfold $(LHAPDFPATH)lib
LIBDIRLIST = $(addprefix -L, $(LIBDIR))

RTL = -Wl,-rpath,
LIBDIRLISTRTL = $(addprefix $(RTL), $(LIBDIR))

SRCDIR = Sources/
INCDIR = -IIncludes/ -IRooUnfold/src -I$(LHAPDFPATH)include

CXX           = g++ -std=c++0x
CXXFLAGS      = -g -Wall -fPIC   	
CXXFLAGS      += $(ROOTCFLAGS) 

SOURCES = ArgParser.cc ConfigVJets.cc functions.cc MiniBonzai.cc
SOURCES += standalone_LumiReWeighting.cc

SRCLIST = $(addprefix $(SRCDIR), $(SOURCES))
OBJLIST = $(SRCLIST:.cc=.o)

.PHONY: all clean

all: runMiniBonzai

# ===========================================================================
.cc.o:
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCDIR)

runMiniBonzai: $(OBJLIST) runMiniBonzai.o  RooUnfold/libRooUnfold.so
	$(CXX) -o runMiniBonzai $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ $(ROOTGLIBS) $(LIBLIST)

runMiniBonzai.o: runMiniBonzai.cc
	$(CXX) -o $@ -c -IIncludes $< $(CXXFLAGS) $(INCDIR)

RooUnfold/libRooUnfold.so:
	$(MAKE) -C RooUnfold

# =========================================================================== 
clean: 
	rm -f *.o Sources/*.o 
