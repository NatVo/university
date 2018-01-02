from utils.lck_sequence import get_lck_seq
import math

ALPHABET = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\n.,/*!:#%[]'

def encode_array(encode_str):

	encode_arr = []
	for i in encode_str:
		encode_arr.append(ALPHABET.find(i))

	return encode_arr

def attack(encode_str, r):

	a = encode_array(encode_str)
	print(a)

	for j in range(0, len()):
		c = (chisl_1(a, r, j) - chisl_2(a) * chisl_3(a, r, j)) / (math.sqrt(zn_1(a) * zn_2(a, r, j)))
		print('c [{}] = {}'.format(j, c))

	'''
	while(True):

	    if cv2.waitKey(1) & 0xFF == ord('q'):
	        break

	'''
def chisl_1(a, r, j):
	sum = 0
	for i in range(0, len(a)):
		sum += (a[i] * r[i + j])
	return sum

def chisl_2(a):
	return sum(a)

def chisl_3(a, r, j):
	sum = 0
	for i in range(0, len(a)):
		sum += r[i + j]
	return sum

def zn_1(a):
	sum_1 = 0
	sum_2 = pow(chisl_2(a), 2)

	for i in range(0, len(a)):
		sum_1 += pow(a[i], 2)
	return sum_1 - sum_2

def zn_2(a, r, j):
	sum_1 = 0
	sum_2 = pow(chisl_3(a, r, j), 2)

	for i in range(0, len(a)):
		sum_1 += pow(r[i + j], 2)
	return sum_1 - sum_2


if __name__ == '__main__':
    encode_str = ''

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

    attack(encode_str, LCK_SEQ)


