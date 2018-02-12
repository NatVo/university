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
            N = (self.p1 - 1) * (self.p2 - 1)
            print('\nN = {}'.format(N))

            gcd_number = self.eiler_function(N)
            print('Функция Эйлера от числа: {} = {}'.format(N, gcd_number))
     

            #message = self.read_file()
            #print('\nИсходное сообщение: {}'.format(message))
    
       
if __name__ == '__main__':
    rsa = RSA(11,
            7)

    rsa.encode()
    
