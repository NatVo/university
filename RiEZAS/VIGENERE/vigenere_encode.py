
ALPHABET = ' abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZабвгдежзиклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ0123456789.,/*!:#%'

def encode(message, key):
    
    key_line = ''
    encode_str = ''

    while (len(key_line) < len(message)):
        key_line += key
    
    key_line = key_line[:len(message)]

    for i in range(0, len(message)):
        index = (ALPHABET.find(message[i]) + ALPHABET.find(key_line[i])) % len(message)
        #print('index:{}'.format(ALPHABET[index]))
        encode_str += ALPHABET[index]
    print('\nЗашифрованное сообщение:{}'.format(encode_str))
    f = open('encode.txt', 'w')
    f.write(encode_str)
    f.close()
    
    key_f = open('key.txt', 'w')
    key_f.write(key)
    key_f.close()



if __name__ == '__main__':
    message = input('\nВведите сообщение:')
    key = input('\nВведите ключ:')

    encode(message, key)
