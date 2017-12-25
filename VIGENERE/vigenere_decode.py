
ALPHABET = ' abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZабвгдежзиклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ0123456789.,/*!:#%'

def decode():
    
    key = ''
    key_line = ''
    encode_str = ''
    decode_str = ''

    with open('encode.txt') as f:
        encode_str = f.readline()
    
    with open('key.txt') as key_f:
        key = key_f.readline()

    while (len(key_line) < len(encode_str)):
        key_line += key
    
    key_line = key_line[:len(encode_str)]

    
    print('\nЗашифрованное сообщение: {}'.format(encode_str))
    print('Ключ: {}'.format(key_line))

    for i in range(0, len(encode_str)):
        index = (ALPHABET.find(encode_str[i]) - ALPHABET.find(key_line[i])) % len(encode_str)
        #print('index:{}'.format(index))
        decode_str += ALPHABET[index]
    print('\nРасшифрованное сообщение: {}'.format(decode_str)) 

if __name__ == '__main__':
    decode()
