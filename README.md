TreeAnalysis
============

Clone this file to either TreeAnalysis2012 or TreeAnalysis2011

For 2012 data analysis do:
git clone git@github.com:iihe-cms-sw/TreeAnalysis.git TreeAnalysis2012

For 2011 data analysis do:
git clone git@github.com:iihe-cms-sw/TreeAnalysis.git TreeAnalysis2011

Be aware that a rootlogon.C is provided. This is needed to load ROoUnfold
automatically.

Once you have cloned the repository, you just have to build the RooUnfold-1.1.1
that is provided. This RooUnfold is a sloghtly modified version of the one 
you can download at CERN. That is why it is provided here.

To build it, nothing hard:

$ cd DYJets/RooUnfold-1.1.1
$ make

Bravo ! You have compiled the RooUnfold classes and you are ready to use it.


