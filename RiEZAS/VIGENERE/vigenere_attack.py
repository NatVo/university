ALPHABET = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,/*!?;:#%[]абвгдежзиклмнопрстуфхцчшщъыьэюяАБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
#ALPHABET_MESS = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,/*!?;:#%[]'
ALPHABET_MESS = 'abcdefghijklmnopqrstuvwxyz0123456789 .,/*!?;:#%[]'
ALPHABET_KEY = ''

def attack(encode_str):
    for freq in range (1, 7):
        print('\n', 'i = ', freq)
        counter = 0
        letters = []
        
        letters.append(encode_str[counter])
        
        pred_set = get_ded_set(encode_str[counter])
        print('pred set: ', pred_set)
        while((counter + freq) < len(encode_str)):
            counter += freq
            new_set = get_ded_set(encode_str[counter])
            
            pred_set = interseq(pred_set, new_set)
            inter = interseq(pred_set, new_set)
            print('==========================================')
            print('new_set:', new_set)
            print('\ninter:')
            print(inter)
            print('==========================================')
            print()
            letters.append(encode_str[counter])
            
        print('pred_set:', pred_set)
        print('new_set:', new_set)
        print(letters)


def get_ded_set(letter):
    ded_set = []

    for i in (ALPHABET_MESS):
        index = (ALPHABET.find(letter) - ALPHABET_MESS.find(i)) % len(ALPHABET)
        ded_set.append(ALPHABET[index])
    
    #print(ded_set)
    return ded_set


def interseq(s1, s2):
    return list(set(s1).intersection(s2))

def key_alph(key):
    return ''.join(set(key))

if __name__ == '__main__':
	#key = input('\nВведите ключ:')
	#ALPHABET_KEY = key_alph(key)
	#print(ALPHABET_KEY)

    encode_str = ''

    with open('encode.txt') as f:
        encode_str = f.readline()

    print('encode_str: {}'.format(encode_str))
    attack(encode_str)

