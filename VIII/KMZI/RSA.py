#!/Documents/venv/uni/bin/python3

from utils.common import Common
from fractions import gcd

from DS import DigitalSignature

class RSA(Common):

    def __init__(self, p1, p2, mess_path = 'message.txt', dec_path = 'dec_message.txt'):
        self.p1 = p1
        self.p2 = p2
        self.mess_path = mess_path
        self.dec_path = dec_path
   
    def encode(self, message, stride, bit_cap, MOD, key):
        self.rem_file(self.dec_path)
       
        i = 0
        while (len(message) >= stride):
            i += stride
            chunk = message[0:stride]
            message = message[stride:]

            chunk_int, chunk_bin = self.chunk_to_int(chunk, stride, bit_cap)
            
            chunk_dec = self.dihotomy(chunk_int, key, MOD)
            #chunk_dec_ = pow(chunk_int, key) % MOD
            #print(chunk_bin, len(chunk_bin), chunk_int, chunk_dec)
            
            chunk_hex = hex(chunk_dec)
            self.write_to_file(self.dec_path, chunk_hex + '\\', 'a')
    
    def decode(self, message, stride, bit_cap, MOD, key, DS):
       
        out_message = ''

        message_arr = message.split('\\')

        for i in message_arr:
            try:
                chunk_int = int(i, 0)
            except:
                pass
            chunk_bin = self.int_to_bin(chunk_int, stride * bit_cap)

            chunk_dec = self.dihotomy(chunk_int, key, MOD)
            #chunk_dec_ = pow(chunk_int, key) % MOD
            #print(chunk_bin, len(chunk_bin), chunk_int, chunk_dec)

            chunk_symb = self.int_to_chunk(chunk_dec, stride, bit_cap)
            out_message += chunk_symb

        print('\nРасшифрованное сообщение: \n{}'.format(out_message))
          
            

    def encode_decode(self, message, stride, bit_cap, MOD, key, flag):
        
        if (flag == 'encode'):
            self.rem_file(self.dec_path)

        i = 0
        out_message = ''

        while (len(message) >= stride):
            i += stride
            chunk = message[0:stride]
            message = message[stride:]

            chunk_int, chunk_bin = self.chunk_to_int(chunk, stride, bit_cap)
            
            chunk_dec = self.dihotomy(chunk_int, key, MOD)
            #chunk_dec_ = pow(chunk_int, key) % MOD
            #print(chunk_bin, len(chunk_bin), chunk_int, chunk_dec)

            chunk_symb = self.int_to_chunk(chunk_dec, stride, bit_cap)
            out_message += chunk_symb
              
            if (flag == 'encode'): 
                self.write_to_file(self.dec_path, chunk_symb, 'a')
        
        if (flag == 'decode'):
            print('\nРасшифрованное сообщение: \n{}'.format(out_message))

            
    def get_e_1(self, N):
        eiler_func = self.eiler_function(N)
        print('\nФункция Эйлера от числа: {} = {}'.format(N, eiler_func))

        mpr_list = self.find_mutually_prime(N)
        print('\nВзаимно простые числа с числом {}: {}'.format(N, mpr_list))
        
        while (1):
            try:
                i = int(input('\nВыберите взаимно простое число из списка: '))
                e = mpr_list[i]
                break
            except:
                print('Некорректный ввод!')

        return e

    def get_e_2(self, N):
        e = int(input('\nВведите число e: '))

        while (gcd(e, N) != 1):
            print('Числа e и N не взаимнопростые')
            e = int(input('\nВведите число e: '))
            
        return e
   

    def prep_encode(self, FLAG, FLAG_DS):
        
        prime_p1, _ = self.prime_test(self.p1)
        prime_p2, _ = self.prime_test(self.p2)
        
        #print(prime_p1, prime_p2)

        if (prime_p1 and prime_p2):
            
            _N = self.p1 * self.p2

            N = (self.p1 - 1) * (self.p2 - 1)
            print('\nN = {}'.format(N))
            
            #e = self.get_e_1(N)
            e = self.get_e_2(N)
                    
            print('\nЧисло e = {}, НОД e и N = {}'.format(e, gcd(e, N)))
            d = self.euklid_ext(N, e)
            print('\nЧисло d = {}'.format(d))

            print('\nЗакрытый ключ: ({}, {})'.format(N, d))
            print('\nОткрытый ключ: ({}, {})'.format(_N, e))

            #self.dihotomy(25331478, 1472, 77)
            #print(pow(25331478, 1472) % 77)
            
            message = self.read_file(self.mess_path)
            print('\nИсходное сообщение: \n{}'.format(message))
            
            if (FLAG):
                self.encode_decode(message, 4, 8, int(_N), int(e), 'decode')
            else:
                self.encode(message, 4, 8, int(_N), int(e))
           
            print('СООБЩЕНИЕ ЗАШИФРОВАНО -> dec_meassage.txt\n')
            print('='*100)
            
            if (FLAG_DS):
                ds = DigitalSignature(103)
                ds.prep_ds_enc(True)

        else:
            print('Числа p1 и / или p2 не простые')
   
    def prep_decode(self, FLAG, FLAG_DS):
        if (FLAG_DS):
            pass
        
        message = self.read_file_codecs(self.dec_path)
        print('\nВведите закрытый ключ:')
        
        N = input('\nN = ')
        d = input('\nd = ')
        print(int(N))
        if (FLAG):
            self.encode_decode(message, 4, 8, int(N), int(d), 'decode')
        else:
            self.decode(message, 4, 8, int(N), int(d))

    
            
            #ds = DigitalSignature(103)
            #ds.prep_ds_enc()

       
if __name__ == '__main__':
    #rsa = RSA(47,71)
    #rsa = RSA(11, 7)
    rsa = RSA(
            48353, 
            #33331,
            49333)
            #131071)
    #e = 1498151
    #rsa = RSA(137, 311)
    rsa.prep_encode(False, True)

    #rsa.prep_decode(False) 
