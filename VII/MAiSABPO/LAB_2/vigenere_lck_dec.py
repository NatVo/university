from utils.lck_sequence import get_lck_seq, is_prime
from fractions import gcd
import codecs

def decode(encode_str, key, LCK_SEQ):

    decode_str = ''

    for i in range(0, len(encode_str)):
        index = (ord(encode_str[i]) - LCK_SEQ[key + i]) % 1104
        decode_str += chr(index)

    print('\nРАСШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(decode_str)) 

if __name__ == '__main__':
    encode_str = ''

    key = int(input('\nВЕДИТЕ КЛЮЧ:'))

    encode_str = open('encode_lck.txt', 'r').read()
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(encode_str))

    lck_length = len(encode_str) * 2

    M = 65519
    A = 262077
    C = 123456

    print('\nНОД C и M: {}'.format(gcd(C, M)))
    print('ПРОСТОЕ ЛИ ЧИСЛО M? : {}\n'.format(is_prime(M)))

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    decode(encode_str, key, LCK_SEQ)

