#!/home/nat/Documents/virt_env/uni/bin/python3

from utils.common import Common


class RSA(Common):

    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def encode(self):
        
        prime_p1, _ = self.prime_test(self.p1)
        prime_p2, _ = self.prime_test(self.p2)
        
        print(prime_p1, prime_p2)

        if (prime_p1 and prime_p2):
            
            _N = self.p1 * self.p2

            N = (self.p1 - 1) * (self.p2 - 1)
            print('\nN = {}'.format(N))

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
                    
            print('\nЧисло e = {}'.format(e))
            d = self.euklid_ext(N, e)
            print('\nЧисло d = {}'.format(d))

            print('\nЗакрытый ключ: ({}, {})'.format(_N, e))
            print('\nОткрытый ключ: ({}, {})'.format(N, d))

            self.dihotomy(25331478, 1472, 77)
            #print(pow(25331478, 1472) % 77)
            #message = self.read_file()
            #print('\nИсходное сообщение: {}'.format(message))
    
       
if __name__ == '__main__':
    rsa = RSA(47,
            71)

    rsa.encode()
    
