# =============================== 
# Makefile for ZJets Analysis 
# =============================== 

ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags) 
ROOUNFLIB  = -lRooUnfold

ROOUNFLIBDIR  = -LRooUnfold-1.1.1 
ROOUNFINCDIR  = -IRooUnfold-1.1.1/src

SRCDIR = Sources/
INCDIR = Includes/

CXX           = clang++ -std=c++0x 
CXXFLAGS      = -g -Wall -fPIC   	
CXXFLAGS      += $(ROOTCFLAGS) 
SOFLAGS       = -shared 

SOURCES = getFilesAndHistogramsZJets.cc ConfigVJets.cc HistoSetZJets.cc ZJets.cc functions.cc MergeTop.cc standalone_LumiReWeighting.cc
SOURCES += FinalUnfoldZJets.cc UnfoldingSyst.cc writeFastPlotsTex.cc unfoldingFunctionsZJets.cc
#SOURCES = UnfoldingZJets.cc getFilesAndHistogramsZJets.cc ConfigVJets.cc HistoSetZJets.cc ZJets.cc functions.cc MergeTop.cc
SRCLIST = $(addprefix $(SRCDIR), $(SOURCES))
OBJLIST = $(SRCLIST:.cc=.o)

# ===========================================================================
runZJets: $(OBJLIST) runZJets.o
	clang++ -std=c++0x $^ -o runZJets $(ROOTGLIBS) $(ROOUNFLIBDIR) $(ROOUNFLIB) -lLHAPDF
	rm runZJets runZJets.o

.cc.o:
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(ROOUNFINCDIR)

runZJets.o: runZJets.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(ROOUNFINCDIR)

runFinalUnfold: $(OBJLIST) runFinalUnfold.o
	clang++ -std=c++0x $^ -o runFinalUnfold $(ROOTGLIBS) $(ROOUNFLIBDIR) $(ROOUNFLIB) -lLHAPDF
	rm runFinalUnfold runFinalUnfold.o

runFinalUnfold.o: runFinalUnfold.cc
	clang++ -std=c++0x -c -IIncludes $< -o $@ $(CXXFLAGS) $(ROOUNFINCDIR)

# =========================================================================== 
clean: 
	rm -f *.o Sources/*.o 
	rm runFinalUnfold runZJets



