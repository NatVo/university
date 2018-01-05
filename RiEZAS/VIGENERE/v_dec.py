def decode(key):
    
    key_line = ''
    encode_str = ''
    decode_str = ''

    with open('enc.txt') as f:
        encode_str = f.readline()
    
    while (len(key_line) < len(encode_str)):
        key_line += key
    
    key_line = key_line[:len(encode_str)]
   
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(encode_str))

    for i in range(0, len(encode_str)):
        #index = (ord(encode_str[i]) - ord(key_line[i])) % 256
        index = (ord(encode_str[i]) - ord(key_line[i])) % 1104
        #print('index:{}'.format(index))
        decode_str += chr(index)
    print('\nРАСШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(decode_str))

if __name__ == '__main__':
    key = input('\nВЕДИТЕ КЛЮЧ:')
    decode(key)



