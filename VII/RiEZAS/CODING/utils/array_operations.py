import numpy as np
from operator import itemgetter
#from utils.tree import Node


def sort_array(array):
    return sorted(array, key = itemgetter(1))

def get_sum(array):
    array_num = array[:, 1].astype(int)
    return np.sum(array_num)

def split_array(array):
    min = 10000000
    for i in range(1, len(array)):

        sum_left = get_sum(array[:i])
        sum_right = get_sum(array[i:])

        diff = abs(sum_left - sum_right)

        if (diff < min):
            min = diff
            left = array[:i]
            right = array[i:]
    if (len(left) == 1 or len(right) == 1):            
        left = np.squeeze(left)
        right = np.squeeze(right)
        #print('\nl_a:{},\nr_a:{}\n'.format(left, right))
    return left, right

'''
def count_number_of_input(message):
    array  = []
    unique_letters = ''.join(set(message))
    
    for i in unique_letters:
        array.append([
                i, message.count(i), Node([i, message.count(i)])
            ])
    return sort_array(array)
'''
