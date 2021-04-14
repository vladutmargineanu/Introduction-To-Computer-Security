#!/usr/bin/env python3

import sys
import binascii

if __name__ == "__main__":

   with open(sys.argv[1], "rb") as f:
        in_data = f.read()
        
   try:
        offset = hex(in_data.index(b'Kvr'))
        print(offset)
   except ValueError:
        print('Invalid file')
