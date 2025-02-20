class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
class Tree:
    def __init__(self):
        self.root = None
    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        print(node.data, end = " ")
        self.inorder(node.right)
    def preorder(self, node):
        if node is None:
            return
        print(node.data, end = " ")
        self.preorder(node.left)
        self.preorder(node.right)
    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.data, end = " ")

tree = Tree()
tree = Tree()
tree.root = Node(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)

print("\nInorder: ")
tree.inorder(tree.root)
print("\nPreorder: ")
tree.preorder(tree.root)
print("\nPostorder: ")
tree.postorder(tree.root)

  