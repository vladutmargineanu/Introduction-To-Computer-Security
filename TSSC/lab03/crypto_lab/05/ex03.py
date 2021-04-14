with open('otp.txt') as f:
    encrypt = f.read().strip()
    print(encrypt)

    for key in range(256):
        message = "".join([chr(ord(c) ^ key) for c in encrypt])
        if message.isprintable():
            print(message)
