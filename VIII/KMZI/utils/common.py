import numpy as np

from math import sqrt
from fractions import gcd


class Common():

    def __init__(self):
        pass

    def read_file(self, file_name):
        return open(file_name, 'r').read()

    def write_to_file(self, file_name, line):
        return open(file_name, 'w').write(line)

    def prime_test(self, number):
        if (number < 1):
            print('Число < 1 !!!')
        else:
            i = 2
            while i < (round(sqrt(number))):
                if (number % i == 0):
                    return False, i
                    break
                i+=1
            return True, None

    def eiler_function(self, number):
        
        fact = []
        prime, div = self.prime_test(number)
        
        if (not prime):
            fact.append(div)
            
            while (not prime):
                number = int(number / div)
                prime, div = self.prime_test(number)
                if (div != None):
                    fact.append(div)
                #print(prime, ' ', number)
            
            fact.append(number)
        
        #print(fact)
        unique_fact = list(set(fact))
        #print(unique_fact)
        
        for i in range(len(unique_fact)):   
            fact.remove(unique_fact[i])
            unique_fact[i] -= 1
        
        fact = np.asarray(fact)
        unique_fact = np.asarray(unique_fact)
        #print(fact, unique_fact)

        return (np.prod(fact) * np.prod(unique_fact))
    
    def gcd(self):
        pass
    
    
    def find_mutually_prime(self, number):
        
        mpr_list = []

        for i in range(1, number):
            if (gcd(i, number) == 1):
                mpr_list.append(i)
        
        return mpr_list
    
    def euklid_ext(self, a, b):

        t1 = 0
        t2 = 1
        r = 1
        
        while (r != 0):
            r = a % b
            c = a // b

            t3 = t1 - t2 * c
            
            #print(c, a, b, r, t1, t2, t3)

            a = b
            b = r

            t1 = t2
            t2 = t3

        if (t1 < 0):
            return (t2 + t1)
        else:
            return t1


    def power_of_2(self, number):
        counter = 1
        pow_2 = 2

        while (number >= pow_2):
            #print(counter, two_power, '\n')
            counter += 1
            pow_2 *= 2
        counter -= 1
        return counter

    def dihotomy(self, number, power, mod):

        pow_2 = self.power_of_2(power)
        pow_n = number
        pow_list = [pow_n]

        for i in range(1, pow_2 + 1):
            pow_n = pow(pow_n, 2) % mod
            pow_list.append(pow_n)

        while (1):
            left = power - pow(2, pow_2)
            if (left < 1):
                break
            pow_2 = self.power_of_2(left)
            pow_n = pow_n * pow_list[pow_2] % mod
            #print('left: ', left, 'pow_2: ', pow_2, 'pow_n:', pow_n)
            power = left
        
        print(pow_n)
