#!/usr/bin/env python3
import ctypes
import os
import pdb
import sys

_code = None

def our_CodeSolFunc(ticketPrice, offerPrice):
   global _nxtH
   num_ticketPrice = len(ticketPrice)
   array_type = ctypes.c_int * num_ticketPrice
   num_offerPrice = len(offerPrice)
   array_type2 = ctypes.c_int * num_offerPrice
   _code.testCode(array_type(*ticketPrice),
                  array_type2(*offerPrice),
                  ctypes.c_int(num_ticketPrice),
                  ctypes.c_int(num_offerPrice))
   return

def runTest(libName):
    global _code
    # load the lib where c fuction is stored.
    _code = ctypes.CDLL(libName)

    ticketPrice = [5, 3, 7, 8, 5]
    offerPrice = [4, 8, 3]
    our_CodeSolFunc(ticketPrice, offerPrice)

    

if __name__ == '__main__':
    #get the libName
    libName = 'libTickets.so'
    if len(sys.argv ) >= 2:
        libName = sys.argv[1]
    if not os.path.isfile(libName):
        print("The lib  '%s' is not avaiable" % libName )
        exit()
    runTest(libName)
