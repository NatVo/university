from fractions import gcd

from math import sqrt
from itertools import count, islice

def isPrime(n):
    if n < 2: 
    	return False
    for number in islice(count(2), int(sqrt(n)-1)):
        if not n%number:
            return False
    return True

if __name__ == '__main__':

	q = int(input('ВВЕДИТЕ q: '))
	if (isPrime(q)):
		p = q * 2 + 1
		A = int(input('ВВЕДИТЕ A: '))

		if (A > 1 and A < (p - 1) and (pow(A, q) % p) != 1):

			X = int(input('ВВЕДИТЕ СЕКРЕТНОЕ ЧИСЛО : '))
			if (X > 1 and X < (p- 1)):
				Y = (pow(A, X)) % p
				print('ОТКРЫТЫЙ КЛЮЧ: ', Y)
				k = int(input('ВВЕДИТЕ k: '))

				if (gcd(k, p - 1) == 1):
					m = int(input('ВВЕДИТЕ СООБЩЕНИЕ: '))
					r = pow(A, k) % p
					e = m * pow(Y, k) % p

				print("ПЕРЕДАВАЕМОЕ СООБЩЕНИЕ: ({}, {})".format(e, r))
				m = e * pow(r, (p -1 - X)) % p
				print("РАСШИФРОВАННОЕ СОСОБЩЕНИЕ: ", m)

