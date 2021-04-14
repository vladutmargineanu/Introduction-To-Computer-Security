#!/usr/bin/env python3

import sys
import binascii

def extract_line(file, output, hex_offset):
    """Fetch a single byte (or character) from file at hexadecimal offset hex_offset"""
    offset = int(hex_offset, base=16)
    file.seek(offset)
    
    elem = file.read(1)
    
    
    while elem:
    	output.write(elem)
    	elem = file.read(1)
    

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: cryptolocker.py <SOURCE_FILE> <DESTINATION_FILE> offset")
        sys.exit(2)
        
    if sys.argv[3] is None:
        print("Number line is nul")
        sys.exit(2)

    # read the input file
    f = open(sys.argv[1], "rb")
    g = open(sys.argv[2], "wb")
    
    line = extract_line(f, g, sys.argv[3])
    
    f.close()
    g.close()
