message = "FIRE_NUKES_MELA!"
new_message = "SEND_NUDES_MELA!"

iv_old = "7ec00bc6fd663984c1b6c6fd95ceeef1"
iv = ""
for i in range(len(message)):
    h = int(iv_old[i * 2 : (i + 1) * 2], 16)
    iv_new = hex(ord(message[i]) ^ ord(new_message[i]) ^ h)[2:]
    iv += iv_new

print(iv)
