#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

SRC="../../build/"

def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)
    pdb.set_trace()

if __name__ == '__main__':
    #get the libName
    libName = 'libIndexer.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    lib=SRC+libName
    if not os.path.isfile(lib):
        print("The lib  '%s' is not avaiable" % lib )
        exit()
    runTest(lib)
