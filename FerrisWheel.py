#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

_code = None

def our_CodeSolFunc(childWeight, maxWeight):
   global _nxtH
   num_childWeight = len(childWeight)
   array_type = ctypes.c_int * num_childWeight
   _code.testCode(array_type(*childWeight), ctypes.c_int(num_childWeight),
                         ctypes.c_int(maxWeight))
   return

def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)
    #pdb.set_trace()
    #_code.testCode.argtypes((ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int))
   
    childWeight = [7, 2, 3, 9]
    maxWeight = 10
    our_CodeSolFunc(childWeight, maxWeight)

    

if __name__ == '__main__':
    #get the libName
    libName = 'libFerrisWheel.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    if not os.path.isfile(libName):
        print("The lib  '%s' is not avaiable" % libName )
        exit()
    runTest(libName)
