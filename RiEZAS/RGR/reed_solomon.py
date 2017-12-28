from irreducible_polynome import list_of_irr_polynoms

import numpy as np

n = 4
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
'''
def find_sub_irr_polyn(polynom):
    
    counter = 1

    while (polynom[counter] == 0):
        counter += 1

    return polynom[counter:]
'''

def gen_polynom(p_number):
    
    p = []
    
    for i in range(1, (p_number + 1)):
        p.append([1, NUMBER_TABLE[i]])

    print('\n', p) 
    
    g = np.zeros(10)
    print(g)
    p_1 = p[0]
    p_2 = p[1]

    counter = 0

    while (counter < p_number):
        for i in range(0, len(p_1)): 
            for j in range(0, len(p_2)):
                print('i+j', i + j)
                if (g[i + j] == 0):
                    g[i + j] = MULT_TABLE[p_1[i], p_1[j]]
                    print(g[i + j])
                else:
                    g[i + j] = ADD_TABLE[g[i + j], MULT_TABLE[p_1[i], p_1[j]]]
        counter += 1
        p_1 = g
        p_2 = p[counter]

        print('\n', g)





if __name__ == '__main__':
    

    POLY_LIST = list_of_irr_polynoms(GF, n)

    IRRED_POL = POLY_LIST[0]
    #IRRED_POL = find_sub_irr_polyn(irr_polynom)
    print(IRRED_POL)
    number_table(IRRED_POL, n)
    print(NUMBER_TABLE, '\n')
    
    ADD_TABLE = additive_matrix(n)
    MULT_TABLE = mult_matrix(n)

    gen_polynom(3)
