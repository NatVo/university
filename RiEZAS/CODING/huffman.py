#from operator import itemgetter
from utils.tree_huffman import Node, B_Tree 
from utils.code_decode import Cipher
from utils.output import output_array, output_dict
from utils.array_operations import sort_array

def count_number_of_input(message):
    array  = []
    unique_letters = ''.join(set(message))
    
    for i in unique_letters:
        array.append([
                i, message.count(i), Node([i, message.count(i)])
            ])
    return sort_array(array)


def shift_array(begin, array, insert):

    array.append([None])
    
    for i in range(len(array) - 1, begin, -1):
        array[i] = array[i - 1]
    array[begin] = insert
    return array

def create_triplet(array):
    summa = array[0][1] + array[1][1]
    return [None, summa, Node([None, summa], array[0][2], array[1][2])]


def create_tree(array):
    summa = array[0][1] + array[1][1]
    
    element = create_triplet(array)

    del array[0]
    del array[0]
    
    #print('\n====================') 
    #output_array_values(array)
    #print('====================\n')

    i = 0
    while (array[i][1] < summa):
           i += 1
           if (i == len(array)):
               break

    #print('i: {}'.format(i))
    array = shift_array(i, array, element)

    return array


if __name__ == '__main__':

    message = input('Enter message:')
    #message = 'it is my striiiiing!!!!'
    count_letters = count_number_of_input(message)
    #output_array(count_letters)
   
    while(len(count_letters) != 2):
        count_letters = create_tree(count_letters) 
        #print()
        #output_array(count_letters)

    root = create_triplet(count_letters)[2]

    tree = B_Tree()
    print('===========================================================\n')
    tree._printTree(root, 0)
    print('\n===========================================================')
    
    SLOVAR = tree.GetSlovar(root)
    output_dict(SLOVAR)

    cipher_encode = Cipher()
    
    encode_str = cipher_encode.encode(message, SLOVAR)
    print('\nENCODE MESSAGE:\n{}'.format(encode_str))

    cipher_decode = Cipher(encode_str, root)
    decode_str = cipher_decode.GetDecodeStr()
    print('\nDECODE MESSAGE:\n{}'.format(decode_str))
