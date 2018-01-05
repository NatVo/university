from utils.lck_sequence import get_lck_seq, is_prime
from fractions import gcd

#ALPHABET = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\n.,/*!:#%[]'

def chaeck_if_prime(M):
    pass

def encode(message, key, LCK_SEQ):
    
    key_line = ''
    encode_str = ''

    for i in range(0, len(message)):
        #index = (ALPHABET.find(message[i]) + LCK_SEQ[key + i]) % len(ALPHABET)
        #index = (ord(message[i]) + ord(key_line[i])) % 256
        index = (ord(message[i]) + LCK_SEQ[key + i]) % 1104

        encode_str += chr(index)
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ: \n{}'.format(encode_str))

    f = open('encode_lck.txt', 'w')
    f.write(encode_str)
    f.close()


if __name__ == '__main__':
    
    print('\nСООБЩЕНИЕ:\n')
    message = open('message.txt', 'r').read()

    print(message)

    key = int(input('\nВВЕДИТЕ КЛЮЧ:'))

    #lck_length = int(input('Введите длину конгруэнтной последовательности: '))
    lck_length = len(message) * 2

    #M= int(input('Введите M: '))
    #A = int(input('Введите А: '))
    #C = int(input('Введите C: '))

    M = 65519 #63949
    #A = 65520 
    A = 262077
    C = 333

    print('НОД C и M: {}'.format(gcd(C, M)))
    print('ПРОСТОЕ ЛИ ЧИСЛО M? : {}'.format(is_prime(M)))
    '''
    for i in range(M, 65536):
        print('i: ', i)
        print(is_prime(i))
        print()
    '''

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    encode(message, key, LCK_SEQ)


