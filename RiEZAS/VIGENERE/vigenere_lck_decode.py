from utils.lck_sequence import get_lck_seq

ALPHABET = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\n.,/*!:#%[]'

def decode(encode_str, key, LCK_SEQ):

    decode_str = ''

    print('\nЗашифрованное сообщение: {}'.format(encode_str))

    for i in range(0, len(encode_str)):
        index = (ALPHABET.find(encode_str[i]) - LCK_SEQ[key + i]) % len(ALPHABET)
        #print('index:{}'.format(index))
        decode_str += ALPHABET[index]
    print('\nРасшифрованное сообщение: {}'.format(decode_str)) 

if __name__ == '__main__':
    encode_str = ''

    key = int(input('Введите ключ: '))
    #lck_length = int(input('Введите длину конгруэнтной последовательности: '))

    #M= input('Введите M: ')
    #A = input('Введите А: ')
    #C = input('Введите C: ')

    with open('encode_lck.txt') as f:
        encode_str = f.readline()

    lck_length = len(encode_str) * 2

    M = 63949 #65713
    A = 15357
    C = 33413

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    decode(encode_str, key, LCK_SEQ)

