class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    elif key > root.data:
        root.right = insert(root.right, key)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

def search(root, key):
    if root is None or root.data == key:
        return root
    if root.data < key:
        return search(root.right, key)
    return search(root.left, key)

# Construct the binary search tree
keys = [5, 3, 8, 2, 4, 7, 10]
root = None
for key in keys:
    root = insert(root, key)

# Search for key 7 and print the search path
node = search(root, 7)
print("Search path:", end=" ")
while node:
    print(node.data, end=" ")
    if node.data < 7:
        node = node.right
    elif node.data > 7:
        node = node.left
    else:
        break
