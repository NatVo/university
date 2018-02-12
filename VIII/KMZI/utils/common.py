from math import sqrt
import numpy as np

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


        

