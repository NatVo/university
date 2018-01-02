from utils.lck_sequence import get_lck_seq

ALPHABET = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\n.,/*!:#%[]'

def chaeck_if_prime(M):
    pass

def encode(message, key, LCK_SEQ):
    
    key_line = ''
    encode_str = ''

    for i in range(0, len(message)):
        index = (ALPHABET.find(message[i]) + LCK_SEQ[key + i]) % len(ALPHABET)
        #print('index:{}'.format(ALPHABET[index]))
        encode_str += ALPHABET[index]
    print('\nЗашифрованное сообщение:{}'.format(encode_str))

    f = open('encode_lck.txt', 'w')
    f.write(encode_str)
    f.close()


if __name__ == '__main__':
    message = input('\nВведите сообщение: ')
    key = int(input('Введите ключ: '))

    #lck_length = int(input('Введите длину конгруэнтной последовательности: '))
    lck_length = len(message) * 2

    #M= input('Введите M: ')
    #A = input('Введите А: ')
    #C = input('Введите C: ')

    M = 63949 #65713
    A = 15357
    C = 33413

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    encode(message, key, LCK_SEQ)


