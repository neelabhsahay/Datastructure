#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

_code = None

def our_CodeSolFunc(a, b):
   global _code
   #_code.testCode(ctypes.c_char_p(a), ctypes.c_int(b))
   _code.testCode(a.encode('ascii'), ctypes.c_int(b))
   return



def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)
    # set the arg type.
    #_code.testCode.argtypes = ( ctypes.c_int, ctypes.c_int)
    #instruct = 'DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD'
    instruct = '??????R????LUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD'
    #instruct = '??????R??????U??????????????????????????LD????D?'
    instList = list(instruct)
    num_intruct = len(instList)
    print( num_intruct)
    our_CodeSolFunc(instruct, num_intruct)

    

if __name__ == '__main__':
    #get the libName
    libName = 'libCoin.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    if not os.path.isfile(libName):
        print("The lib  '%s' is not avaiable" % libName )
        exit()
    runTest(libName)
