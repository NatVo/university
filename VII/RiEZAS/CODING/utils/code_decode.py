class Cipher:

    def __init__(self, encode_str = '', root = None):
        self.encode_str = encode_str
        self.decode_str = ''
        self.root = root
   
    def encode(self, message, SLOVAR): 
       for i in message:
           self.encode_str += SLOVAR.get(i)
       return self.encode_str
   
   
    def decode(self, node, i):
        try:
            if (node.value[0] == None):
                if (self.encode_str[i] == '0'):
                    self.decode(node.left, i = i + 1)
                else:
                    self.decode(node.right, i = i + 1)
            else:
                self.decode_str += node.value[0] 
                self.decode(self.root, i)
        except:
            pass

    def GetDecodeStr(self):
        self.decode(self.root, 0)
        return self.decode_str
