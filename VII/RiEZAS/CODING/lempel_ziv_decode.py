import numpy as np
from utils.lempel_ziv_op import add_element_to_array


DECODE_LINE = ''


def print_array_as_line(array):
    string = ''

    for i in array:
        string = string + i[0] + ' '
    print(string)


def decode (ENCODE_LINE, table):
    global DECODE_LINE

    current_str = ''
    prev_str = ''
   
    
    for i in ENCODE_LINE:
        
        current_w = int(i[0])
        #print('current_w: {}'.format(current_w))                     
        #print('prev_str: {}'.format(prev_str))
        DECODE_LINE += table[current_w][0]
       
        current_str = table[current_w][0]
        #print('current_str: {}'.format(current_str))

        for letter in current_str:
            new_element = prev_str + letter
            #print('new_element: {}'.format(new_element))
            if (not np.isin(new_element, table)):
                table = add_element_to_array(table, new_element)
      
        
        prev_str = current_str
        prev_w = current_w
    
    return DECODE_LINE
