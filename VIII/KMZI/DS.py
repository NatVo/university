#!/Documents/venv/uni/bin/python3
from fractions import gcd
import random

from utils.common import Common

class DigitalSignature(Common):

    def __init__(self, q, dec_path = 'dec_message.txt'):
        self.q = q
        self.dec_path = dec_path
    
    def get_p_1(self, q):
        b = 1
        p = q * b + 1
        prime_p, _ = self.prime_test(p)

        while(not prime_p):
            b += 1
            p = q * b + 1
            prime_p, _ = self.prime_test(p)

        return p, b

    def get_p_2(self, q):
        
        b = int(input('\nВведите число b: '))
        p = q * b + 1
        prime_p, _ = self.prime_test(p)

        while (not prime_p):
            b = int(input('\nВведите число b: '))
            p = q * b + 1
            prime_p, _ = self.prime_test(p)
            print('Числo p не простое')
           
        return p, b

    def get_chunk(self, message):
        message_arr = message.split('\\')
        
        total_int = 0
        for i in message_arr:
            try:
                total_int += int(i, 0)
            except:
                pass
        return total_int


    def create_ds(self, message, q, a, p, x, FLAG_MANY_DS):
        
        if (FLAG_MANY_DS):
            message_arr = message.split('\\')
        else:
            message_arr = [1]
        
        total_ds = '\n'

        for i in message_arr:
            try:
                if (FLAG_MANY_DS):
                    chunk_int = int(i, 0)
                else:
                    chunk_int = self.get_chunk(message)
            except:
                pass
            
            h = self.hash_func(chunk_int, q)
            print('{}, h = {}'.format(chunk_int, h))
            
            while(1):
                k = random.randint(1, q)
                
                r = self.dihotomy(a, k, p)
                r_ = r % q
                print('h = {}, k = {}, r = {}, r_ = {}'.format(h, k, r, r_))
                if (r_ != 0):
                    break
            
            s = (x * r_ + k * h)
            print('s = {}'.format(s))
            total_ds += (hex(r_) + '\\' + hex(s))
            
        self.write_to_file(self.dec_path, total_ds, 'a')

    def prep_ds_enc(self, FLAG_MANY_DS):

        prime_q, _ = self.prime_test(self.q)
        
        if (prime_q):
            print('\nq = {}'.format(self.q))

            p, b = self.get_p_1(self.q)
            print('\np = {}'.format(p))
            print('\nb = {}'.format(b))
            
            base = int(input('\nВведите любое число, чтобы сгененрировать число a: '))

            #base = random.randint(0, 16)
            
            a = pow(base, b)
            dih_gcd = self.dihotomy(a, self.q, p)
            print('a = {}, НОД a и p = {}'.format(a, dih_gcd))

            x = int(input('\nВведите x - секртеный ключ: '))
            #x = random.randint(0, 32)

            print('\nx - секретный ключ = {}'.format(x))
            
            y = self.dihotomy(a, x, p)
            print('\nx - открытый ключ = {}'.format(y))
            
            message = self.read_file_codecs(self.dec_path)

            self.create_ds(message, self.q, a, p, x, FLAG_MANY_DS)
                
        
        else:
            print('Число q некорректно!')

            


'''

if __name__ == '__main__':
    
    DS = DigitalSignature(103)
    DS.prep_ds_enc()
'''
