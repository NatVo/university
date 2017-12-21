import numpy as np


def find_2_degree(number):
    power = 0

    while (pow(2, power) < number):
        power += 1

    print('power: {}'.format(power))
    return power
