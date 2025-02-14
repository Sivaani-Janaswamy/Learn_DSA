class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
class Tree:
    def __init__(self):
        self.root = None
    def inorder(self):
        if self.root is None:
            return
        inorder(self.root.left)
        print(self.root.data)
        inorder(self.root.right)


  