from utils.output import output_array
from utils.lempel_ziv_op import find_2_degree, add_element_to_array
from lempel_ziv_decode import decode
import numpy as np

ENCODE_LINE = np.empty((0,1))
DECODE_LINE = ''
SLOVAR = np.empty((0,2))

def count_number_of_input(message):
    array = np.empty((0,1))
    unigue_letters = ''.join(set(message))
    counter = 0
    for i in unigue_letters:
        array = add_element_to_array(array, i, counter)      
        counter += 1
       
    return np.sort(array, axis = 0)

def find_pos(element, table):
    global ENCODE_LINE
    position = np.argwhere(table == element)
    position = np.squeeze(position)

    ENCODE_LINE = add_element_to_array(ENCODE_LINE, position[0])


def get_unique_substr(string, table):
    begin = 0
    substr = string[0]

    while (np.isin(substr, table)):
        begin += 1
        substr = string[:begin]
    
    table = add_element_to_array(table, substr)
    begin -= 1
    #print('message: {}'.format(string[begin:]))
    end = len(substr) - 1 
    find_pos(substr[:end], table) 
    
    return string[begin:], table

def fullfill_table(message, table):
    while (len(message) != 1):
        message, table = get_unique_substr(message, table)
   
    find_pos(message, table)
    
    table = add_element_to_array(table, message)
    #print(table)
    return table

def binary_encode(string, table):
    global SLOVAR
    
    counter = 0
    while (len(table[counter][0]) == 1):
        power = find_2_degree(counter)
        binary = bin(int(counter))[2:].zfill(power)
        
        #print('{} : {}'.format(table[counter], binary))

        counter += 1

    binary_str = ''
    for i in string:
        power = find_2_degree(counter)
        binary = bin(int(i[0]))[2:].zfill(power)
       
        table_element = table[counter][0]
        element = np.array([[table_element, binary]])
        SLOVAR = np.append(SLOVAR, element, axis = 0)
        
        binary_str += binary
        counter += 1
    return binary_str


if __name__ == '__main__':
    print('\n================================================')
    message = input('ВВЕДИТЕ СООБЩЕНИЕ: ')
    #message = 'abacabadabacabae'
    #message = 'vnfkgjo gutrh g 423erw'
    count_letters = count_number_of_input(message)
    #output_array(count_letters)
    
    table = fullfill_table(message, count_letters)
    #print(count_letters.shape[0])

    BINARY_ENCODE = binary_encode(ENCODE_LINE, table)
    #print('non_binary_ENCODE_LINE:\n{}'.format(ENCODE_LINE))
    print(SLOVAR)
    print('\nЗАКОДИРОВАННОЕ СООБЩЕНИЕ: {}\n'.format(BINARY_ENCODE))

    DECODE_LINE = decode(ENCODE_LINE, count_letters)
    print('\nРАСКОДИРОВАННОЕ СООБЩЕНИЕ: {}\n'.format(DECODE_LINE))
    print('==================================================\n')
