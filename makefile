###########################################################################
#
# 5/Aug/04: The /usr/lib/gcc-lib/i386-redhat-linux/2.96/libg2c.a library
#           is needed for the Fortran Interface. If this is used the 
#           mainAnalysis.o during linking must be BEFORE the -lg2c    --SP
#
# 3/Apr/05: Defined some static rules to simplify handling and output --LF
#
###########################################################################


# Root variables
ROOTCFLAGS   := $(shell root-config --cflags)
#ROOTLIBS     := $(shell root-config --libs) -lRooFit -lHtml -lMinuit  -L./lib/ 
ROOTLIBS     := $(shell root-config --libs) -lHtml -lMinuit  -L./lib/ 
FORTRANLIBS  := -L../lib/ -L/cern/pro/lib 
LHAPDFLIBS   := -L. /publicfs/atlas/atlasnew/higgs/hgg/zhoums/SoftWares/LHAPDF6/lib/libLHAPDF.a
# Programs
CXX          = g++
CXXFLAGS     = -g -Wall -fPIC -Wno-deprecated 
LDFLAGS      = -g 
SOFLAGS      = -shared 

# Local Includes
INCDIR       = -IMain
INCDIR      += -IDataObject
INCDIR      += -IAnalysisTools
INCDIR      += -Isrc
INCDIR      += -I/publicfs/atlas/atlasnew/higgs/hgg/zhoums/SoftWares/LHAPDF6/include/ 
# Direct to make the directories with the sources:
VPATH  = ./lib  ./bin ./src ./inc ./util
#VPATH += ./Main ./DataObject ./AnalysisTools

# Assign or Add variables
CXXFLAGS    += $(ROOTCFLAGS)
CXXFLAGS    += $(INCDIR)
LIBS        += $(LHAPDFLIBS)
LIBS        += $(ROOTLIBS)

# Data
#CXXSRCS     +=  RecVtx.cc RecJet.cc RecTracks.cc 
#                RecMuMuons.cc RecIdMuons.cc TrueMuons.cc 

# Analysis tools and main code
CXXSRCS     +=  SampleHandler.cxx
CXXSRCS     +=  miniNtuple.cxx
CXXSRCS     +=  MiniTruth.cxx
CXXSRCS     +=  lumi.cxx
#CXXSRCS     +=  FFcalculator_muon.cxx
#CXXSRCS     +=  FFcalculator_electron.cxx
CXXSRCS     +=  LeptonClassifier.cxx
CXXSRCS     +=  ClosureTest.cxx

CXXOBJS      = $(CXXSRCS:.cc=.o)
GARBAGE      = $(CXXOBJS) libana.so *~ lib/*.so lib/*.o ./*/*.o


############################################################################
# Build main.c compiling only the first prereq: ($<) means main.c
############################################################################
runSampleHandler                       :        runSampleHandler.o SampleHandler.o 
make_stackplots                       :        make_stackplots.o SampleHandler.o
runFFcalculator                        :        runFFcalculator.o SampleHandler.o 
runFFApp                        :        runFFApp.o SampleHandler.o 
runcomparisons                        :        runcomparisons.o SampleHandler.o 
runClosureTest                        :        runClosureTest.o SampleHandler.o 
runmakeNtuple                        :        runmakeNtuple.o SampleHandler.o 
runSystematics                        :        runSystematics.o miniNtuple.o
runCutflow_SigOpt                     :        runCutflow_SigOpt.o
runsigScan_HSS                     :        runsigScan_HSS.o
runMiniTruth                       :        runMiniTruth.o MiniTruth.o
runmakePlots                       :        runmakePlots.o miniNtuple.o
##########################################################################
# General rules. The first two need not be specified due to implicit rules, 
# but redefined for the "echo"
############################################################################
%.o : %.cxx %.h
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< 

%.o : %.cxx 
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< 
%    : %.o
	@echo "compiling and linking $@"
	@$(CXX) $(LDFLAGS) $^ \
	        $(FORTRANLIBS) $(LHAPDFLIBS) $(ROOTLIBS) -o $@
	@if [ `ls | grep "\.so"$ | wc -l` != 0 ]; then mv *.so lib/; fi
	@if [ `ls | grep "\.o"$  | wc -l` != 0 ]; then mv *.o  lib/; fi
	@mv $@ bin/

############################################################################
# Build libana.so compiling all prerequisites: ($^) means CXXOBJS 
# ($@) means the target libana.so
############################################################################
libana.so : $(CXXOBJS) 
	@echo "linking libana.so"
	@$(CXX) $(SOFLAGS) $(LDFLAGS) $^ -o $@


############################################################################
# Phony rules (no prerequisites)
############################################################################

.PHONY: clean cln print xemacs backup clnPM

clean :
	@rm -f $(GARBAGE)

cln :
	@rm -f *~ *.o */*~

clnPM :
	@rm -f usePM pairManager.o SingleElectron.o */*~

print :
	@echo compiler  : $(CXX)
	@echo c++ srcs  : $(CXXSRCS)
	@echo c++ objs  : $(CXXOBJS)
	@echo c++ flags : $(CXXFLAGS)
	@echo libs      : $(LIBS)
	@echo so flags  : $(SOFLAGS)
	@echo rootlibs  : $(ROOTLIBS)

xemacs:
#	@xemacs -geometry 160x70+0+100 \
                ${PWD}/*/HtoZZAnalysis.*[hc] \
                ${PWD}/*/Particle.*[hc] &
#	@xemacs -geometry 160x70+300+80 \
	        ${PWD}/*/Analysis.*[hc] &
#	@xemacs -geometry 160x70+600+100 \
                ${PWD}/*/EG_CaloTrack*[hc] \
                ${PWD}/*/RecObject*[hc] &
#                ${PWD}/*/*Muon*[hc] \
	@xemacs -geometry 60x12+0+60 ${PWD}/TDR.par &

