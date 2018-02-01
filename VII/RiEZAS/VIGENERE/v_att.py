def attack(encode_str):

    letter = []
    freq = 0
    KEY = ''

    while(len(letter) == 0):
        freq +=1
        
        counter = 0
        letter = find_key_letter(counter, freq, encode_str)

    '''
        pred_set = get_ded_set(encode_str[counter])
        #print('pred set: ', pred_set)
        while((counter + freq) < len(encode_str)):
            counter += freq
            new_set = get_ded_set(encode_str[counter])
            
            pred_set = interseq(pred_set, new_set)
            inter = interseq(pred_set, new_set)
            #print('==========================================')
            #print('new_set:', new_set)
            #print('\ninter:')
            #print(inter)
            #print('==========================================')
            #print()
            #letters.append(encode_str[counter])
            
        print('pred_set:', pred_set)
    '''
    print('\nДЛИНА КЛЮЧА: {}'.format(freq))
    KEY += str(letter[0])
    #====================================================

    for counter in range(1, freq):
        letter = find_key_letter(counter, freq, encode_str)

        KEY += str(letter[0])

    print('\nКЛЮЧ: {}'.format(KEY))

    '''
        pred_set = get_ded_set(encode_str[counter])
        while((counter + freq) < len(encode_str)):
            counter += freq
            new_set = get_ded_set(encode_str[counter])       
            pred_set = interseq(pred_set, new_set)
            
        print('pred_set:', pred_set)
    '''


def find_key_letter(counter, freq, encode_str):
    pred_set = get_ded_set(encode_str[counter])

    while((counter + freq) < len(encode_str)):
        counter += freq
        new_set = get_ded_set(encode_str[counter])
        
        pred_set = interseq(pred_set, new_set)
        inter = interseq(pred_set, new_set)
        
    return pred_set



def get_ded_set(letter):
    ded_set = []

    for i in range(0, 256):
        if ((i > 31 and i < 59) or 
            (i > 64 and i < 91) or 
            (i > 96 and i < 123) or 
            (i > 191 and i < 256) or
            i == 10 or i == 13 or
            #i == 32 or i == 33 or
            #i == 44 or i == 45 or
            #i == 46 or i == 58 or
            i == 59 or i == 63 or
            i == 150 or i == 151):
                #index = (ord(letter) + 256 - i) % 256
                index = (ord(letter) + 1104 - i) % 1104
                #print('indx: ', index)
                ded_set.append(chr(index))
    
    return ded_set


def interseq(s1, s2):
    return list(set(s1).intersection(s2))

def key_alph(key):
    return ''.join(set(key))

if __name__ == '__main__':

    encode_str = ''

    with open('enc.txt') as f:
        encode_str = f.readline()

    print('\nЗАШИФРОВАННОЕ СООБЩЕНИЕ:\n\n {}'.format(encode_str))
    attack(encode_str)

