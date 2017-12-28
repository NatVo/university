import numpy as np

def create_list(string):
    arr = []
    for i in string:
        arr.append(int(i))

    return arr


def get_prev_irr_poly(POLY_LIST):

    PRED_POLY_LIST = []
    with open('irr_polynoms.txt') as f:
        content = f.readlines()
    content = [x.strip() for x in content]

    for i in content:
        element = create_list(i)
        #element = element.astype(int)
        if (len(element) < len(POLY_LIST[0])):
            PRED_POLY_LIST.append(element)

    #print(PRED_POLY_LIST)    
    return PRED_POLY_LIST

def irr_polynoms(GF, n):

    POLY_LIST = np.empty((0, n + 1))

    for i in range(0, (pow(2, n - 1))):
        polynom = bin(i)[2:].zfill(n - 1)
        polynom = '1' + polynom + '1'
        element = np.array(list(polynom))
        element = np.array([element.astype(int)])
        #print(element)
        POLY_LIST = np.append(POLY_LIST, element, axis = 0)

    #print(POLY_LIST)
    return POLY_LIST

def find_irr_polynoms(POLY_LIST, PRED_POLY_LIST):
    
    non_irr = []
    
    for i in PRED_POLY_LIST:
        #print()
        for j in POLY_LIST:
            _, mod = np.polydiv(j, i)
            mod = mod % 2

            if (len(mod) == 1 and mod[0] == 0):
                non_irr.append(j)
            #print(mod)

    non_irr = np.asarray(non_irr)
    #print(non_irr)

    irr_polynoms = []

    for i in POLY_LIST:
        
        if (not (non_irr == i).all(1).any()):
            irr_polynoms.append(i)

    irr_polynoms = np.asarray(irr_polynoms)
    #print('\n', irr_polynoms)
    return(irr_polynoms)


def list_of_irr_polynoms(GF, n):
    POLY_LIST = irr_polynoms(GF, n)
    PRED_POLY_LIST = get_prev_irr_poly(POLY_LIST)
    return find_irr_polynoms(POLY_LIST, PRED_POLY_LIST)    
    
