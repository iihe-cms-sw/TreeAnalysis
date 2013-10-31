#!/usr/bin/env python
import os, sys, string
import re, time
lepton="DE"
PT="30"
for i in  range(1, 3):
 cmd1="sed -e \"s|.*int doWhat.*|int doWhat = "+str(i)+";|g\" " +"-e \"s|.*string lepSelection.*|string lepSelection = "+str(lepton)+";|g\" " +  " -e \"s|.*int jetPtMin.*| int jetPtMin = "+str(PT) +";|g\"  runDYJets.cc > sranje.cc "
 os.system(cmd1) 
 cmd2="nohup root -b -q sranje.cc++  >& LOG_Lep"+str(lepton)+"_option"+str(i)+"_PT"+str(PT)+".txt & \n"
 print cmd2
 os.system(cmd2)
 time.sleep(120)
 
