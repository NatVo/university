#!/home/nat/Documents/virt_env/uni/bin/python3

from utils.common import Common
from fractions import gcd

class RSA(Common):

    def __init__(self, p1, p2, mess_path = 'message.txt', dec_path = 'dec_message.txt'):
        self.p1 = p1
        self.p2 = p2
        self.mess_path = mess_path
        self.dec_path = dec_path
    
    def encode_decode(self, message, stride, bit_cap, MOD, key, flag):
        
        if (flag == 'encode'):
            self.rem_file(self.dec_path)

        i = 0
        chunk_symb = ''

        while (len(message) > stride):
            i += stride
            chunk = message[0:stride]
            message = message[stride:]

            chunk_int, chunk_bin = self.chunk_to_int(chunk, stride, bit_cap)
            
            chunk_dec = self.dihotomy(chunk_int, key, MOD)
            #chunk_dec_ = pow(chunk_int, key) % MOD
            #print(chunk_bin, len(chunk_bin), chunk_int, chunk_dec)

            chunk_symb += self.bin_to_chunk(chunk_dec, stride, bit_cap)
        
        if (flag == 'decode'):
            print('\nРасшифрованное сообщение: {}'.format(chunk_symb))
            
        if (flag == 'encode'): 
            self.write_to_file(self.dec_path, chunk_symb, 'a')

            
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
   

    def prep_encode(self):
        
        prime_p1, _ = self.prime_test(self.p1)
        prime_p2, _ = self.prime_test(self.p2)
        
        print(prime_p1, prime_p2)

        if (prime_p1 and prime_p2):
            
            _N = self.p1 * self.p2

            N = (self.p1 - 1) * (self.p2 - 1)
            print('\nN = {}'.format(N))
            
            #e = self.get_e_1(N)
            e = self.get_e_2(N)
                    
            print('\nЧисло e = {}'.format(e))
            d = self.euklid_ext(N, e)
            print('\nЧисло d = {}'.format(d))

            print('\nЗакрытый ключ: ({}, {})'.format(N, d))
            print('\nОткрытый ключ: ({}, {})'.format(_N, e))

            #self.dihotomy(25331478, 1472, 77)
            #print(pow(25331478, 1472) % 77)
            
            message = self.read_file(self.mess_path)
            print('\nИсходное сообщение: {}'.format(message))
            self.encode_decode(message, 4, 8, _N, e, 'encode')
            print('СООБЩЕНИЕ ЗАШИФРОВАНО -> dec_meassage.txt\n')
            print('='*100)
    
    def prep_decode(self):
        message = self.read_file(self.dec_path)
        #print('\nЗашифрованное сообщение: {}'.format(message))
        print('\nВведите закрытый ключ:')
        
        N = input('\nN = ')
        d = input('\nd = ')
        print(int(N))
        self.encode_decode(message, 4, 8, int(N), int(d), 'decode')
       
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
    rsa.prep_encode()
    rsa.prep_decode() 
