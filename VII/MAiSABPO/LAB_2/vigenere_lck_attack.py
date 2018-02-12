from utils.lck_sequence import get_lck_seq, is_prime
from fractions import gcd
import math

def encode_array(encode_str):

	encode_arr = []
	for i in range(0, len(encode_str)):		
		encode_arr.append(ord(encode_str[i]))

	return encode_arr

def attack(encode_str, r):

	a = encode_array(encode_str)

	for j in range(0, len(encode_str)):		
		c = (chisl_1(a, r, j) - chisl_2(a) * chisl_3(a, r, j)) / (math.sqrt(zn_1(a) * zn_2(a, r, j)))
		print('c [{}] = {}'.format(j, c))


def chisl_1(a, r, j):
	summa = 0
	for i in range(0, len(a)):
		summa += (a[i] * r[i + j])
	return summa * len(a)

def chisl_2(a):
	return sum(a)

def chisl_3(a, r, j):
	summa = 0
	for i in range(0, len(a)):
		summa += r[i + j]
	return summa

def zn_1(a):
	sum_1 = 0
	sum_2 = pow(chisl_2(a), 2)

	for i in range(0, len(a)):
		sum_1 += pow(a[i], 2)
	sum_1 *= len(a)
	return sum_1 - sum_2

def zn_2(a, r, j):
	sum_1 = 0
	sum_2 = pow(chisl_3(a, r, j), 2)

	for i in range(0, len(a)):
		sum_1 += pow(r[i + j], 2)
	sum_1 *= len(a)
	return sum_1 - sum_2


if __name__ == '__main__':
    encode_str = ''

    encode_str = open('encode_lck.txt', 'r').read()
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(encode_str))

    lck_length = len(encode_str) * 2

    M = 65519
    A = 262077
    C = 123456

    print('\nНОД C и M: {}'.format(gcd(C, M)))
    print('ПРОСТОЕ ЛИ ЧИСЛО M? : {}\n'.format(is_prime(M)))

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    attack(encode_str, LCK_SEQ)
