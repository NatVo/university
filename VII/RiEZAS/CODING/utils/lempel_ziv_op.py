import numpy as np

MIN_DEGREE = 3


def find_2_degree(number):
    power = 0

    while (pow(2, power) < number):
        power += 1

    #print('power: {}'.format(power))
    if (power < MIN_DEGREE):
        return MIN_DEGREE
    else:
        return power

def add_element_to_array(array, element, number = None):
    new_element = np.array([[element]])
    array = np.append(array, new_element, axis = 0)
    return array


