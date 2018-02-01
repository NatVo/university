from utils.lck_sequence import get_lck_seq
import math

#ALPHABET = ' abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\n.,/*!:#%[]'

def encode_array(encode_str):

	encode_arr = []
	for i in encode_str:
		encode_arr.append(ord(i))

	return encode_arr

def attack(encode_str, r):

	a = encode_array(encode_str)
	#print(a)

	for j in range(0, 20):
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
	return sum * len(a)

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

    #M= int(input('Введите M: '))
    #A = int(input('Введите А: '))
    #C = int(input('Введите C: '))

    encode_str = open('encode_lck.txt', 'r').read()
    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n{}'.format(encode_str))

    lck_length = len(encode_str) * 2

    M = 65519 #63949
    #A = 65520 
    A = 262077
    C = 333

    LCK_SEQ = get_lck_seq(A, C, M, lck_length)

    attack(encode_str, LCK_SEQ)


