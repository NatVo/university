def get_lck_seq(A, C, M, length):
    lck_seq = []
    pred = 0
    lck_seq.append(pred)

    for i in range (0, length):
        new_element = (pred * A + C) % M
        pred = new_element
        lck_seq.append(new_element)

    return lck_seq
    
def is_prime(a):
    return all(a % i for i in range(2, a))
