#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

_code = None

def our_CodeSolFunc(startTime, endTime):
   global _code
   num_startTime = len(startTime)
   array_type = ctypes.c_int * num_startTime
   num_endTime = len(endTime)
   array_type2 = ctypes.c_int * num_endTime
   _code.testCode(array_type(*startTime),
                  array_type2(*endTime),
                  ctypes.c_int(num_endTime))
   return

def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)
    #pdb.set_trace()
    #_code.testCode.argtypes((ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int))
   
    #startTime = [3, 4, 5]
    #endTime = [5, 9, 8]
    startTime = [1, 2, 5, 8]
    endTime = [5, 4, 7, 13]
    our_CodeSolFunc(startTime, endTime)

    

if __name__ == '__main__':
    #get the libName
    libName = 'libRestaurent.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    if not os.path.isfile(libName):
        print("The lib  '%s' is not avaiable" % libName )
        exit()
    runTest(libName)
