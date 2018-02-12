#!/home/nat/Documents/virt_env/uni/bin/python3

from utils.common import Common

def change_key_length(message, key):
    
    key_line = ''

    while (len(key_line) < len(message)):
        key_line += key
    
    key_line = key_line[:len(message)]

    return key_line

def xor_strings(str1, str2):
    
    dec_line = ''

    try:
        for i in range(len(str1)):
            xor_symb = ord(str1[i]) ^ ord(str2[i])
            #print('xor_symb [{}]: {}'.format(i, xor_symb))
            dec_line += chr(xor_symb)
        return dec_line
    except:
        print('Ooops! Something wrong!')


class Vernam(Common):

    def __init__(self):
        pass

    def encode_decode(self, inp_path, out_path):
        
        message = self.read_file(inp_path)
        print('\nИсходное сообщение: {}'.format(message))

        key = input('Введите ключ: ')
        key = change_key_length(message, key)
        
        out_message = xor_strings(message, key)
        print('\nПреобразованное сообщние: {}'.format(out_message))
        self.write_to_file(out_path, out_message)

if __name__ == '__main__':

    vernam = Vernam()

    switch = input('\nВыберите действие: \
                \n1 - закодировать сообщение; \
                \n2 - раскодировать сообщение.\n')
    if (switch == '1'):
        vernam.encode_decode('message.txt', 'dec_message.txt')
    else:
        vernam.encode_decode('dec_message.txt', 'message.txt')

