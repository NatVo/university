import numpy as np
from utils.array_operations import split_array

class Node:
    def __init__(self, value, left = None, right = None):
        self.left = left
        self.right = right
        self.value = value


class B_Tree:
    def __init__(self, root = None):
        self.root = root
        self.SLOVAR = {}
        self.CODE = ''

    def insert_element(self, node):
        try:
            if (node != None):
                if (len(node.value) == 1):
                    self.insert_element(node.left)
                    self.insert_element(node.right)
                else:
                
                    left, right = split_array(node.value)
                    node.value = np.array([None])
                    node.left = Node(left)
                    node.right = Node(right)
                    #print('n_2_value: {}'.format(node.value))
                    #print('n_2_left: {}'.format(node.left))
                    #print('n_2_right: {}'.format(node.right))
                    #print(self.root)
                    self.insert_element(self.root)
        except:
            pass


    def _printTree(self, node, flag = 0):
        if (node != None):
            self._printTree(node.left, flag = flag + 10)
            
            print((' ' * flag), node.value)
            
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
