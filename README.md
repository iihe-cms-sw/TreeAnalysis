TreeAnalysis
============

Clone this file to either TreeAnalysis2012 or TreeAnalysis2011

For 2012 data analysis do:

    git clone git@github.com:iihe-cms-sw/TreeAnalysis.git TreeAnalysis2012

if you want to run on:
  1. WJets: move DYJets directory to WJets
  2. TTbar to emu : move DYJets directory to TTbarEMu

Be aware that a rootlogon.C is provided. This is needed to load RooUnfold
automatically. 

Once you have cloned the repository, you just have to build the RooUnfold-1.1.1
that is provided. This RooUnfold is a slightly modified version of the one 
you can download at CERN. That is why it is provided here.

To build it, nothing hard:

    $ cd DYJets/RooUnfold-1.1.1
    $ make clean
    $ make 

Bravo ! You have compiled the RooUnfold classes and you are ready to use it.

Three Makefile are provided. One for each host... If somebody wants to create
a configure script, he can, but I found it easier to have three Makefile and 
create a symbolinc link to the one we want. For example, if you are on lxplus,
you will do this:

    $ ln -s Makefile.lxplus Makefile

I m mostly working on the m-machines, so I do

    $ ln -s Makefile.m6 Makefile

The created link Makefile is mentioned in the .gitignore and will therefore not
be commited.

Now you should have everything setup and you can try to build the executables.
The source code is contained in the Sources and some in DYJets. The code in
Sources will only be compiled into .o files. While the code in DYJets, meanly
some runBlaBla.cc code are dedicated to user executables. For example, after
compilation you will have

    $ ./runZJets

That will use some .o files in the Sources directory.


So, right now you are ready to compile the Sources code. Simply do:

    $ make

It will also create the first executable: runZJets

You can then compile each of the other runBlabla:

    $ make runRecoComparison
    $ make runUnfoldingZJets
    $ make runCombination

Once you ve done this. If there was no error, you can start using the executbles.
The executables come with some options. You can use the option -help to know more
about what it is possible to do.






You can also create some directories that will be needed later:

    $ mkdir HistoFiles PNGFiles

The first directory will contain the .root files created by runDYJets and co.
and containing the histograms used during the whole process up to cross section
measurements.

The second will contain the .png and .pdf plots for all kind of comparison at
several different levels.

These directories are however not considered by git (as can be seen in the .gitignore file).

Next you need to have the data to run on. For this, if your running on m-machine, 
a simple symbolic link will be enough. You can also opy the full directory.

Go to the racine directory TreeAnalysis2012
    
    $ ln -s /THIS_is_wehre_I_store_data/Data_Z_5311 Data_Z_5311
    $ ln -s /THIS_is_wehre_I_store_data/DataTTbarEMu DataTTbarEMu
    $ ln -s /THIS_is_wehre_I_store_data/DataW DataW

#############################
################  quick fix for lxplus from Darin
#############################

# Set up CMSSW ( for root ) 
    cmsrel CMSSW_5_3_0
    cd CMSSW_5_3_0/src
    cmsenv

# Get Git Repository
    git clone git@github.com:iihe-cms-sw/TreeAnalysis.git TreeAnalysis2012

# Setup W+Jets directory
    cd TreeAnalysis2012
    mkdir WJets
    mkdir WJets/DataW
    cp -r DYJets/* WJets/
    cd WJets

--- Get example file
    cmsStage /store/group/phys_smp/WPlusJets/NtuplesTomislav/SMu_8TeV_T_s_channel_dR_5311.root DataW/SMu_8TeV_T_s_channel_dR_5311.root

--- Output directories
    mkdir HistoFiles PNGFiles

---- Compile RooUnfold
    cd RooUnfold-1.1.1
    make
    cd -

--- Quick hacks for making LHAPDF work
    sed -i 's#/user/aleonard/LHAPDF/lib/libLHAPDF.so#/afs/cern.ch/cms/slc5_amd64_gcc434/external/lhapdf/5.8.5/lib/libLHAPDF.so#g' runDYJets.cc
    sed -i 's#/user/aleonard/lhapdf-5.9.1/include/#/afs/cern.ch/cms/slc5_amd64_gcc434/external/lhapdf/5.8.5/include/#g' rootlogon.C
    sed -i 's#NNPDF23_nlo_as_0118#NNPDF20_as_0118_100#g' ComputePDFUncertainties.cc
    sed -i 's#NNPDF23_nlo_as_0118#NNPDF20_as_0118_100#g' runDYJets.cc

--- Run the root file maker
    root -b runDYJets.cc

