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

CXX           = g++ -std=c++0x
CXXFLAGS      = -g -Wall -fPIC   	
CXXFLAGS      += $(ROOTCFLAGS) 

SOURCES = ArgParser.cc getFilesAndHistogramsZJets.cc ConfigVJets.cc HistoSetZJets.cc ZJets.cc functions.cc MergeTop.cc standalone_LumiReWeighting.cc
SOURCES += FinalUnfoldZJets.cc UnfoldingSyst.cc writeFastPlotsTex.cc unfoldingFunctionsZJets.cc UnfoldingZJets.cc RecoComparison.cc
SOURCES += PlotSettings.cc

SRCLIST = $(addprefix $(SRCDIR), $(SOURCES))
OBJLIST = $(SRCLIST:.cc=.o)

# ===========================================================================
runZJets: $(OBJLIST) runZJets.o
	$(CXX) $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runZJets $(ROOTGLIBS) $(LIBLIST)

.cc.o:
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCDIR)

runZJets.o: runZJets.cc
	$(CXX) -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR) 

runRecoComparison: $(OBJLIST) runRecoComparison.o
	$(CXX) $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runRecoComparison $(ROOTGLIBS) $(LIBLIST)

runRecoComparison.o: runRecoComparison.cc
	$(CXX) -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

runUnfoldingZJets: $(OBJLIST) runUnfoldingZJets.o
	$(CXX) $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runUnfoldingZJets $(ROOTGLIBS) $(LIBLIST)

runUnfoldingZJets.o: runUnfoldingZJets.cc
	$(CXX) -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

runFinalUnfold: $(OBJLIST) runFinalUnfold.o
	$(CXX) $(LIBDIRLIST) $(LIBDIRLISTRTL) $^ -o runFinalUnfold $(ROOTGLIBS) $(LIBLIST)

runFinalUnfold.o: runFinalUnfold.cc
	$(CXX) -c -IIncludes $< -o $@ $(CXXFLAGS) $(INCDIR)

dispatcher: runZJets dispatcher.cc
	$(CXX) -pthread dispatcher.cc -o dispatcher

# =========================================================================== 
clean: 
	rm -f *.o Sources/*.o 



