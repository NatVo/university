#!/Documents/venv/uni/bin/python3
from fractions import gcd
import random

from utils.common import Common

class DigitalSignature(Common):

    def __init__(self, dec_path = 'dec_message.txt'):
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

    
    def check_ds(self, message, ds):
        
        r_ = int(ds.split('\\')[0], 0)
        s = int(ds.split('\\')[1], 0)

        #print(s, r_ )
        print('\nПРОВЕРКА ЦИФРОВОЙ ПОДПИСИ')
        y = int(input('\nВведите открытый ключ ЭЦП: '))
        q = int(input('\nВведите простое число q: '))
        a = int(input('\nВведите число a: '))
        p = int(input('\nВведите число p: '))

        ds_sum = self.get_sum_chunk_int(message)

        h = self.hash_func(ds_sum, q)
        
        
        v = self.dihotomy(h, (q - 2), q)
        z1 = (s * v) % q
        z2 = ((q - r_) * v) % q


        u = (pow(a, z1) * pow(y, z2)) % p % q
        #print(ds_sum, h, v, z1, z2, u)

        if (u == r_):
            return True
        else:
            return False

        

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
                    chunk_int = self.get_sum_chunk_int(message)
            except:
                pass
            
            h = self.hash_func(chunk_int, q)
            #print('{}, h = {}'.format(chunk_int, h))
            
            while(1):
                k = random.randint(1, q)
                
                r = self.dihotomy(a, k, p)
                r_ = r % q
                #print('h = {}, k = {}, r = {}, r_ = {}'.format(h, k, r, r_))
                if (r_ != 0):
                    break
            
            s = (x * r_ + k * h)
            print('s = {}'.format(s))
            total_ds += (hex(r_) + '\\' + hex(s))
            
        self.write_to_file(self.dec_path, total_ds, 'a')

    def prep_ds_enc(self, FLAG_MANY_DS):
        q = int(input('\nВведите простое число q: '))
        prime_q, _ = self.prime_test(q)
        
        if (prime_q):
            print('\nq = {}'.format(q))

            p, b = self.get_p_1(q)
            print('\np = {}'.format(p))
            print('\nb = {}'.format(b))
            
            base = int(input('\nВведите любое число, чтобы сгененрировать число a: '))

            #base = random.randint(0, 16)
            
            a = pow(base, b)
            dih_gcd = self.dihotomy(a, q, p)
            print('a = {}, НОД a и p = {}'.format(a, dih_gcd))

            x = int(input('\nВведите x - секрeтный ключ: '))
            #x = random.randint(0, 32)

            print('\nx - секретный ключ = {}'.format(x))
            
            y = self.dihotomy(a, x, p)
            print('\ny - открытый ключ = {}'.format(y))
            
            message = self.read_file_codecs(self.dec_path)

            self.create_ds(message, q, a, p, x, FLAG_MANY_DS)
                
        
        else:
            print('Число q некорректно!')

            
