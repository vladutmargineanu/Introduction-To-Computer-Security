#!/usr/bin/env python3

import sys
import binascii

def xor_bytes(ba1, ba2):
    return bytes([_a ^ _b for _a, _b in zip(ba1, ba2)])
    
if __name__ == "__main__":

    if len(sys.argv) < 4:
      print("Usage: cryptolocker.py <ENCODED_LINE> <ENCODED_BINARY> <DESTINATION_FILE_DECODED>")
      sys.exit(2)
           
    f = open(sys.argv[1], "rb")
    first_string = f.read()

    second_string = "Poate ii fac pe internet,\nOri ii fac la imprimanta,\nCa-mi vin banii ca pe banda."
        

    second_string = second_string.encode()
    print(len(first_string))
    print(len(second_string))

    key_first = xor_bytes(first_string, second_string)
    # Obtin cheia: b'CCCC()5+{;({+2CCCCCCCCCC()5+{;({+2CCCCCCCCCC()5+{;({+2CCCCCCCCCC()5+{;({+2CCCCCC'
    print(len(key_first))
    print(key_first)
    
    # Am observat ca se repeta in key_first
    key = b'()5+{;({+2CCCCCCCCCC'
    
    print(len(key))
    print(key)
    
    g = open(sys.argv[2], "rb")
    text = g.read()
    
    decoded = ""
    for i in range(0, len(text)):
    	decoded += chr(text[i] ^ key[i % len(key)])
    	
    # save the encrypted file
    with open(sys.argv[3], "w") as s:
        s.write(decoded)
    	
    print(decoded)
    
    
    
    
