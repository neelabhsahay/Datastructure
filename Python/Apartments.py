#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

_code = None

def our_CodeSolFunc(desiredSize, aptSize, threshold):
   global _nxtH
   num_desiredSize = len(desiredSize)
   array_type = ctypes.c_int * num_desiredSize
   num_aptSize = len(aptSize)
   array_type2 = ctypes.c_int * num_aptSize
   _code.testCode(array_type(*desiredSize),
                  array_type2(*aptSize),
                  ctypes.c_int(num_desiredSize),
                  ctypes.c_int(num_aptSize),
                  ctypes.c_int(threshold))
   return

def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)

    desiredSize = [60, 45, 80, 60]
    aptSize = [30, 60, 75]
    threshold = 10
    our_CodeSolFunc(desiredSize, aptSize, threshold)

    

if __name__ == '__main__':
    #get the libName
    libName = 'libApartments.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    if not os.path.isfile(libName):
        print("The lib  '%s' is not avaiable" % libName )
        exit()
    runTest(libName)
