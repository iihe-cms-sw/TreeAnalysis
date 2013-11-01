#!/usr/bin/env python
import os, sys, string
import re, time

#--------------------------------------------------------------------------------
def loopHasNotStarted(logName):

    command = "cat " + logName + " > tmp.log"
    os.system(command)

    catFile = open("tmp.log","r")
    for line in catFile:
        if "Processing :" in line:
            os.system("rm tmp.log")
            return false


    os.system("rm tmp.log")
    return true

#--------------------------------------------------------------------------------


#--------------------------------------------------------------------------------
def dispacher(lepton = "DE", PT = 30):

    for i in range(1, 3):
        # Create the .cc file based on runDYJets.cc
        tmpFile = "tmp_" + str(lepton) + "_" + str(PT) + "_" + str(i)
        tmpCCFile = tmpFile + ".cc"
        tmpLogFile = tmpFile + ".log"

        cmdSetJob = "sed "
        cmdSetJob += " -e \"s|int doWhat.*|int doWhat = " + str(i) + ";|g\""
        cmdSetJob += " -e \"s|string lep.*|string lep = \\\"" + str(lepton) + "\\\";|g\""
        cmdSetJob += " -e \"s|int jetPtMin.*|int jetPtMin = " + str(PT) + ";|g\""
        cmdSetJob += " runDYJets.cc > " + tmpCCFile

        print cmdSetJob
        os.system(cmdSetJob)

        cmdExecJob = "nohup root -b -q " + tmpCCFile + "++ &> " + tmpLogFile + " &"
        print cmdExecJob
        #os.system(cmdExecJob)

        # Wait for the loop to start before going to next job
        #while loopHasNotStarted(tmpLogFile):
        #    time.sleep(2)

#--------------------------------------------------------------------------------


#--------------------------------------------------------------------------------
if __name__ == "__main__":
    dispacher("DE", 30)
    #dispacher("DE", 20)

#--------------------------------------------------------------------------------
