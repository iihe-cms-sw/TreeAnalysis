#!/bin/sh
#rsync -e ssh --verbose --progress --stats --archive --update TSDr/ lads.phy.hr:~/dr/TSDr/ 
#rsync -e ssh --verbose --progress --stats --archive --update lxplus420.cern.ch:/afs/cern.ch/work/t/tseva/test/CMSSW_5_3_7/src/SherpaNew/BugraDEAdd1/ BugraDEAdd1/ 
rsync -e ssh --verbose --progress --stats --archive --update m0.iihe.ac.be:~/analysis/TreeAnalysis2012/WJets2012/HistoFiles/ HistoFiles/
