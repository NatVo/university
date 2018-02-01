
def encode(message, key):
    
    key_line = ''
    encode_str = ''

    while (len(key_line) < len(message)):
        key_line += key
    
    key_line = key_line[:len(message)]

    for i in range(0, len(message)):
        #index = (ord(message[i]) + ord(key_line[i])) % 256
        index = (ord(message[i]) + ord(key_line[i])) % 1104

        #print('index:{}'.format(ALPHABET[index]))
        encode_str += chr(index)
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ: \n{}'.format(encode_str))

    f = open('enc.txt', 'w')
    f.write(encode_str)
    f.close()



if __name__ == '__main__':
    #message = input('\nВведите сообщение:')
    print('\nСООБЩЕНИЕ:\n')
    message = open('message.txt', 'r').read()

    print(message)

    key = input('\nВВЕДИТЕ КЛЮЧ:')

    encode(message, key)

