from utils.array_operations import sort_array, split_array
from utils.tree_shannon_fano import Node, B_Tree
from utils.code_decode import Cipher
from utils.output import output_array, output_dict

import numpy as np

def count_number_of_input(message):
    array = np.empty((0,2))
    unigue_letters = ''.join(set(message))
    
    for i in unigue_letters:
        new_array = np.array([[i, message.count(i)]])
        array = np.append(array, new_array, axis = 0)
       
    return np.sort(array, axis = 0)

if __name__ == '__main__':
    message = input('Enter message: ')
    #message = 'ghj hjkuiop ghjio'
    count_letters = count_number_of_input(message)
    #output_array(count_letters)
    #print()
    left, right = split_array(count_letters)
    
    root = Node(np.array([None]), Node(left), Node(right))
    #print(root)
    tree = B_Tree(root)
    #tree._printTree(root, 0)
    
    #print(len(left))
    print()
    tree.insert_element(root)
    print("\n======================================================\n")
    tree._printTree(root, 0)
    print("\n======================================================\n")

    SLOVAR = tree.GetSlovar(root)
    output_dict(SLOVAR)

    cipher_encode = Cipher()
    
    encode_str = cipher_encode.encode(message, SLOVAR)
    print('\nENCODE MESSAGE:\n{}'.format(encode_str))

    cipher_decode = Cipher(encode_str, root)
    decode_str = cipher_decode.GetDecodeStr()
    print('\nDECODE MESSAGE:\n{}'.format(decode_str))
