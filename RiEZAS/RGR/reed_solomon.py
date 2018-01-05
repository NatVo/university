from irreducible_polynome import list_of_irr_polynoms

import random
import numpy as np

n = 4 #ext Galua
t = 2 #mistakes
k = 7 #useful code (k + t)  = N - total message
GF = 2
NUMBER_TABLE = []
ADD_TABLE = []
MULT_TABLE = []


def additive_matrix(n):
 
    fin = pow(2, n)
    add_matrix = np.empty([fin, fin])

    for i in range(0, fin):
        for j in range(0, fin):
            add_matrix[i, j] = int(i ^ j)
    add_matrix = add_matrix.astype(int)

    print(add_matrix, '\n')
    return add_matrix

def mult_matrix(n):
    fin = pow(2, n)
    
    mult_matrix = np.empty([fin, fin])

    for i in range(0, fin):
        for j in range(0, fin):
            if (i != 0 and j != 0):
                p_1 = NUMBER_TABLE.index(i)
                p_2 = NUMBER_TABLE.index(j)
                mult_matrix[i, j] = NUMBER_TABLE[(p_1 + p_2) % (fin - 1)]
            else:
                mult_matrix[i, j] = 0
            
            #mult_matrix[i, j] = NUMBER_TABLE[(p_1 + p_2) % (n - 1)]
    mult_matrix = mult_matrix.astype(int)

    print(mult_matrix)
    return mult_matrix

def get_element(i, j):
    arr = []
    arr.append(i + 1)

    for i in range (0, j):
        arr.append(0)

    return arr



def mod_matrix(k, t, g):
    row = pow(2, n) - 1
    mod_matrix = np.empty([row, k + t])
    mod_matrix = mod_matrix.astype(str)

    for i in range(0, row):
        for j in range(0, k + t):
            if (j < t):
                tmp_s = list('0'*t)
                tmp_s[j] = str(i + 1)
                mod_matrix[i, j] = ''.join(tmp_s)
            else:
                div = get_element(i, j)
                #print('div: ', div)
                mod = polyn_dev(div, g)
                string = ''.join(str(e) for e in mod)
                mod_matrix[i, j] = string 

    print('\n', mod_matrix)
    return mod_matrix


def find_pos_in_mod_mtrx(MOD_MATRIX, k, t, s):

    j_x = 0
    i_x = 0
    row = pow(2, n) - 1

    for i in range(0, row):
        for j in range(0, k + t):
            if (MOD_MATRIX[i, j] == s):
                j_x = j
                i_x = i

    return i_x, j_x



def fill_number_table(element, n):
    global NUMBER_TABLE

    str_1 = '0' * (n - len(element))
    
    str_2 = ''
    for i in element:
        str_2 += str(int(i))

    string = str_1 + str_2
    string = string[1:]
    number = int(string, 2)
    #print('string:', string)
    #print('number:', number)
    NUMBER_TABLE.append(number)


def number_table(IRRED_POL, n):
    #number_table = []
    fin = pow(2, n) - 1
    n += 1
    IRRED_POL[0] = 0
    
    pred = np.array([1])
    fill_number_table(pred, n)
    factor = np.array([1, 0])

    for i in range (0, fin):
        new_element = np.polymul(pred, factor)
        #print(new_element)

        if (len(new_element) == n):
            #print('!: ', new_element)
            if (new_element[0] == 1):
                new_element[0] = 0
                new_element = new_element + IRRED_POL
                new_element = new_element % 2

                #print('new_element: ', new_element)
        pred = new_element
        fill_number_table(new_element, n)


def sum_mult(tmp):
    s_1 = []
    s_2 = [0]

    for i in range(0, len(tmp[0])):
        s_1.append(tmp[0][i])
    s_1.append(0)

    for i in range(0, len(tmp[1])):
        s_2.append(tmp[1][i])

    s = []

    for i in range(0, len(s_1)):
        s.append(ADD_TABLE[s_1[i], s_2[i]])
    #print('s:\n', s)
    return s


def gen_polynom(p_number):
    
    p = []

    for i in range(1, (p_number + 1)):
        p.append([1, NUMBER_TABLE[i]])
    
    counter = 1
    p_1 = p[0]

    while (counter < p_number):
        
        p_2 = p[counter]
        tmp = []

        for j in range(0, len(p_2)):
            tmp_1 = []
            for i in range(0, len(p_1)): 
                tmp_1.append(MULT_TABLE[p_1[i], p_2[j]])
            tmp.append(tmp_1)

            #print(tmp, '\n')
            
        p_1 = sum_mult(tmp)
        #print('p_1: ', p_1)

        counter += 1
    return p_1

def print_polyn(polyn):
    counter = len(polyn) - 1
    string = ''
    for i in polyn:
        string += str(i) + 'x^' + str(counter) + ' + '
        counter -= 1
    print('\n', string)

def generate_seq(symb_number):

    num_seq = []
    bit_seq = ''

    for i in range(0, symb_number):
        number = random.randint(1, pow(2, n) - 1)
        num_seq.append(number)
        bit_seq += bin(number)[2:].zfill(n)

    #num_seq = [1, 2, 3, 4, 5]
    return num_seq, bit_seq

def print_bit_seq(num_seq):
    bit_seq = ''
    for i in num_seq:
        bit_seq += bin(i)[2:].zfill(n)
    print('\n', bit_seq)


def sum_div(sub_div, dev):
    res = []
    #print('in: ', sub_div, ' ', dev)

    for i in range(0, len(sub_div)):
        res.append(ADD_TABLE[sub_div[i], dev[i]])

    counter = 0
    while (res[counter] == 0):
        counter += 1
    res = res[counter:]

    return res

def find_factor(sub_div, dev):
    i = dev[0]
    j = 0
    while (MULT_TABLE[i, j] != sub_div[0]):
        j += 1
    f = MULT_TABLE[i, j]

    for i in range(0, len(dev)):
        dev[i] = MULT_TABLE[dev[i], j]

    #print('new_dev: ', dev)
    return dev


def polyn_dev(div, dev):
    #div = [1, 2, 3, 4, 5, 0, 0]
    #dev = [1, 6, 3] #(!!! n = 3)

    sub_div = div[:len(dev)]
    div = div[len(dev):]

    while (1):
        new_dev = find_factor(sub_div, dev)
        sub_div = sum_div(sub_div, new_dev)

        #print('res: ', sub_div)

        while (len(sub_div) < len(dev)):
            try:
                sub_div.append(div[0])
                div = div[1:]
            except:
                return sub_div
    
        #print('div: ', div)
        #print('res_2: ', sub_div, '\n')

def new_num_seq(num_seq, mod_mistakes):
    num_seq = num_seq[::-1]
    mod_mistakes = mod_mistakes[::-1]

    for i in range(0, len(mod_mistakes)):
        num_seq[i] = mod_mistakes[i]

    return num_seq[::-1]

if __name__ == '__main__':
    

    POLY_LIST = list_of_irr_polynoms(GF, n)

    IRRED_POL = POLY_LIST[0]
    print('\nНЕПРИВОДИМЫЙ ПОЛИНОМ:')
    print_polyn(IRRED_POL)

    number_table(IRRED_POL, n)
    print('\n', NUMBER_TABLE, '\n')
    
    print('\nАДДИТИВНАЯ МАТРИЦА:')

    ADD_TABLE = additive_matrix(n)

    print('\nМУЛЬТИПЛИКАТИВНАЯ МАТРИЦА:')
    MULT_TABLE = mult_matrix(n)

    g = gen_polynom(t)
    #g = [1, 6, 3]

    print('\n', g)
    print('\nГЕНЕРАТИВНЫЙ ПОЛИНОМ:')
    print_polyn(g)

    num_seq, bit_seq = generate_seq(k)

    print('\n', bit_seq)
    print('\n', num_seq)

    for i in range(0, t):
        num_seq.append(0)

    print_polyn(num_seq)

    mod_mistakes = polyn_dev(num_seq, g)
    print("ОСТАТОК: ", mod_mistakes)

    mistake_num_seq = new_num_seq(num_seq, mod_mistakes)

    print_polyn(mistake_num_seq)

    mistake_pos = int(input("ВВЕДИТЕ ПОЗИЦИЮ ОШИБКИ: "))
    mistake = int(input("ВВЕДИТЕ ЗНАЧЕНИЕ ОШИБКИ: "))

    mistake_num_seq[mistake_pos] = mistake

    print('\nПОСЛЕДОВАТЕЛЬНОСТЬ С ОШИБКОЙ: ')
    print_polyn(mistake_num_seq)
    print_bit_seq(mistake_num_seq)

    detect_mistakes_mod = polyn_dev(mistake_num_seq, g)
    print("НОВЫЙ ОСТАТОК: ", detect_mistakes_mod)

    detect_mistakes_mod = ''.join(str(e) for e in detect_mistakes_mod)
    #print(detect_mistakes_mod)

    MOD_MATRIX = mod_matrix(k, t, g)

    i_, j = find_pos_in_mod_mtrx(MOD_MATRIX, k, t, detect_mistakes_mod)
    print('i_ = ', i_)
    print('j = ', j)
    
    pos = len(mistake_num_seq) - j - 1

    i = mistake_num_seq[pos]
    print('i = ', i)
    

    error_correct = ADD_TABLE[i, i_ + 1]

    #print(error_correct)

    mistake_num_seq[pos] = error_correct

    print('\nИСПРАВЛЕННАЯ ПОСЛЕДОВАТЕЛЬНОСТЬ: ')
    print_polyn(mistake_num_seq)
    print_bit_seq(mistake_num_seq)
    
