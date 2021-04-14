from Crypto.Cipher import AES
from Crypto import Random

iv = "\x00" * 16
BLOCK_SIZE = 32
PADDING = b'#'

def decrypt(key, iv, data):
    aes = AES.new(key, AES.MODE_CBC, iv)
    data = aes.decrypt(data)
    return data

with open('secret.enc', 'rb') as f:
    data = f.read()

key = data[0:32]
data_02 = data[32:]

f_out_decrypt = open("secret_not.jpg", 'wb')
decrypt_value = decrypt(key, iv, data_02).rstrip(PADDING)
f_out_decrypt.write(decrypt_value)
f_out_decrypt.close();
