from utils.lck_sequence import get_lck_seq, is_prime
from fractions import gcd

def decode(encode_str, key, LCK_SEQ):

    decode_str = ''

    for i in range(0, len(encode_str)):
        #index = (ALPHABET.find(encode_str[i]) - LCK_SEQ[key + i]) % len(ALPHABET)
        #index = (ord(encode_str[i]) - ord(key_line[i])) % 256
        index = (ord(encode_str[i]) - LCK_SEQ[key + i]) % 1104
        #print('index:{}'.format(index))
        decode_str += chr(index)
    print('\nРАСШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(decode_str)) 

if __name__ == '__main__':
    encode_str = ''

    key = int(input('\nВЕДИТЕ КЛЮЧ:'))
    #lck_length = int(input('Введите длину конгруэнтной последовательности: '))

    #M= int(input('Введите M: '))
    #A = int(input('Введите А: '))
    #C = int(input('Введите C: '))

    #with open('encode_lck.txt') as f:
        #encode_str = f.readline()

    encode_str = open('encode_lck.txt', 'r').read()
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(encode_str))

    lck_length = len(encode_str) * 2

    M = 65519 #63949
    #A = 65520 
    A = 262077
    C = 333

    print(gcd(C, M))

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    decode(encode_str, key, LCK_SEQ)

