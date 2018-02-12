from utils.lck_sequence import get_lck_seq, is_prime
from fractions import gcd
import codecs


def encode(message, key, LCK_SEQ):
    
    key_line = ''
    encode_str = ''

    for i in range(0, len(message)):
        index = (ord(message[i]) + LCK_SEQ[key + i]) % 1104
        encode_str += chr(index)

    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ: \n{}'.format(encode_str))

    f = codecs.open('encode_lck.txt', 'w').write(encode_str)


if __name__ == '__main__':
    
    print('\nСООБЩЕНИЕ:\n')
    message = codecs.open('message_lck.txt', 'r', 'cp1251').read()
    print(message)

    key = int(input('\nВВЕДИТЕ КЛЮЧ:'))

    lck_length = len(message) * 2

    M = 65519 
    A = 262077
    C = 123456
    
    print('\nНОД C и M: {}'.format(gcd(C, M)))
    print('ПРОСТОЕ ЛИ ЧИСЛО M? :\n'.format(is_prime(M)))


    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    encode(message, key, LCK_SEQ)
