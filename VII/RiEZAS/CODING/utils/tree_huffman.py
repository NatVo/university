
class Node:
    def __init__(self, value, left = None, right = None):
        self.left = left
        self.right = right
        self.value = value


class B_Tree:

    def __init__(self):
        self.SLOVAR = {}
        self.CODE = ''
        #self.root = None

    def _printTree(self, node, flag = 0):
        if (node != None):
            self._printTree(node.left, flag = flag + 10)
            print((' ' * flag) + str(node.value))
            self._printTree(node.right, flag = flag + 10)

    def _fillDictionary(self, node):
        if (node.left != None):
            self.CODE += '0'
            self._fillDictionary(node.left)
        
        if (node.right != None):
            self.CODE += '1'
            self._fillDictionary(node.right)

        if (node.value[0] != None):
            self.SLOVAR.update({node.value[0]:self.CODE})

        self.CODE = self.CODE[:-1]

    def GetSlovar(self, node):
        self._fillDictionary(node)
        return self.SLOVAR

'''
    def add_root(self, pointer):
        if (self.root == None):
            self.root = pointer

    def printTree(self):
        if(self.root != None):
            self._printTree(self.root, 0)
'''












