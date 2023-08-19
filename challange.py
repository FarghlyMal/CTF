def initialize(key):
    S = list(range(256))
    j = 0
    for i in range(256):
        j = (j + S[i] + key[i % len(key)]) % 256
        S[i], S[j] = S[j], S[i]
    return S

def generate_keystream(S, length):
    i = 0
    j = 0
    while True:
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        yield S[(S[i] + S[j]) % 256]

def confusion(data, key):
    key = [ord(c) for c in key]
    S = initialize(key)
    keystream = generate_keystream(S, len(data))
    encrypted = bytearray()
    for byte, key_byte in zip(data, keystream):
        encrypted.append(byte ^ key_byte)
    return bytes(encrypted)

def the_correct_way(data, key):
    return confusion(data, key)
def may_or_not(solo):
    valid="\x63\x62\x75\x74\x7e\x23\x76\x75\x54\x4f\x62\x23\x72\x49\x53"
    for h in range (len(solo)) :
     operation_x= chr(ord(solo[h]) ^ int(0x10))
     if operation_x!=(valid[h]):
      print("bad :(")
      return 0
    return solo

def UGot_ME(value):
    got_it= value
    
    area_51 = b'\x19\x1dWj\xd3\x15|\xde\x0b\xb3\xfe\x96q*Y\xec\xd2C"Rc8\xe0\x83\xa9\x9e\xc5\xc8'
    allowed_to_be = the_correct_way(area_51, got_it)
    print("Flag :{}".format(allowed_to_be.decode("utf-8")))


galf=input("Enter Correct Flag :) ")
sandro = galf[14::-1]
lol=may_or_not(sandro)
if lol:
    UGot_ME(lol)
    
    



