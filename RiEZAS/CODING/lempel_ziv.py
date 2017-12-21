from utils.output import output_array
from utils.lempel_ziv_op import *
import numpy as np


def count_number_of_input(message):
    array = np.empty((0,3))
    unigue_letters = ''.join(set(message))
    counter = 0
    for i in unigue_letters:
        new_array = np.array([[i, counter, bin(counter)[2:].zfill(3)]])
        array = np.append(array, new_array, axis = 0)
        counter += 1
       
    return np.sort(array, axis = 0)

if __name__ == '__main__':
    #message = input('Enter message: ')
    message = 'abacabadabacabae'
    count_letters = count_number_of_input(message)
    output_array(count_letters)

    count_letters_length = count_letters.shape[0] - 1
    
    find_2_degree(9)
    

    print(np.isin('c', count_letters))
