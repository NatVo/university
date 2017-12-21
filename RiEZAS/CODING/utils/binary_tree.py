class Node:
    def __init__(self, val):
        self.l = None
        self.r = None
        self.v = val

class Tree:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def add(self, val):
        if(self.root == None):
            self.root = Node(val)
        else:
            self._add(val, self.root)
	
    def _add(self, val, node):
        if(val < node.v):
            if(node.l != None):
                self._add(val, node.l)
            else:
                node.l = Node(val)
        else:
            if(node.r != None):
                self._add(val, node.r)
            else:
                node.r = Node(val)
	
    def printTree(self):
        if(self.root != None):
            self._printTree(self.root, 0)

    def _printTree(self, node, flag = 0):
        #print('flag =  ', flag)
        if(node != None):
            self._printTree(node.l, flag = flag + 3)
            print('f: ', flag)
            print((' ' * flag) + str(node.v))
            self._printTree(node.r, flag = flag + 3)

tree = Tree()
tree.add(3)
tree.add(4)
tree.add(0)
tree.add(8)
tree.add(2)
tree.printTree()















































