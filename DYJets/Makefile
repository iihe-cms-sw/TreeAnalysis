# =============================== 
# Makefile for ZJets Analysis 
# =============================== 

ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags) 
ROOUNFLIB     = -lRooUnfold

LIB = RooUnfold LHAPDF
LIBLIST = $(addprefix -l, $(LIB))

#LIBDIR = RooUnfold-1.1.1 /user/aleonard/LHAPDF/lib
LIBDIR = RooUnfold-1.1.1 /usr/local/lib
#LHAPDFLIBDIR  = $(SRT_LHAPATH_SCRAMRTDEL)/../../../lib
LIBDIRLIST = $(addprefix -L, $(LIBDIR))
RTL = -Wl,-rpath,
LIBDIRLISTRTL = $(addprefix $(RTL), $(LIBDIR))

SRCDIR = Sources/
INCDIR = -IIncludes/ -IRooUnfold-1.1.1/src -I/usr/local/include

CXX           = clang++ -std=c++0x 
CXXFLAGS      = -g -Wall -fPIC   	
CXXFLAGS      += $(ROOTCFLAGS) 

SOURCES = ArgParser.cc getFilesAndHistogramsZJets.cc ConfigVJets.cc HistoSetZJets.cc ZJets.cc functions.cc MergeTop.cc standalone_LumiReWeighting.cc
SOURCES += FinalUnfoldZJets.cc UnfoldingSyst.cc writeFastPlotsTex.cc unfoldingFunctionsZJets.cc UnfoldingZJets.cc RecoComparison.cc
SOURCES += PlotSettings.cc

SRCLIST = $(addprefix $(SRCDIR), $(SOURCES))
OBJLIST = $(SRCLIST:.cc=.o)

# ===========================================================================
runZJets: $(OBJLIST) runZJets.o
	clang++ -std=c++0x $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runZJets $(ROOTGLIBS) $(LIBLIST)

.cc.o:
	clang++ -std=c++0x -c $< -o $@ $(CXXFLAGS) $(INCDIR)

runZJets.o: runZJets.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR) 

runRecoComparison: $(OBJLIST) runRecoComparison.o
	clang++ -std=c++0x $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runRecoComparison $(ROOTGLIBS) $(LIBLIST)

runRecoComparison.o: runRecoComparison.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

runUnfoldingZJets: $(OBJLIST) runUnfoldingZJets.o
	clang++ -std=c++0x $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runUnfoldingZJets $(ROOTGLIBS) $(LIBLIST)

runUnfoldingZJets.o: runUnfoldingZJets.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

runFinalUnfold: $(OBJLIST) runFinalUnfold.o
	clang++ -std=c++0x $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runFinalUnfold $(ROOTGLIBS) $(LIBLIST)

runFinalUnfold.o: runFinalUnfold.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

# =========================================================================== 
clean: 
	rm -f *.o Sources/*.o 



