def decode(key):
    
    key_line = ''
    encode_str = ''
    decode_str = ''

    with open('enc.txt') as f:
        encode_str = f.readline()
    
    while (len(key_line) < len(encode_str)):
        key_line += key
    
    key_line = key_line[:len(encode_str)]
   
    print('\nЗашифрованное сообщение: {}'.format(encode_str))

    for i in range(0, len(encode_str)):
        index = (ord(encode_str[i]) - ord(key_line[i])) % 256
        #print('index:{}'.format(index))
        decode_str += chr(index)
    print('\nРасшифрованное сообщение: {}'.format(decode_str)) 

if __name__ == '__main__':
    key = input('\nВведите ключ:')
    decode(key)



