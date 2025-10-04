import sys


class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def bt_insert(root, val):
    if root is None:
        return Node(val)
    if val < root.data:
        root.left = bt_insert(root.left, val)
    else:
        root.right = bt_insert(root.right, val)
    return root


def bt_size(root):
    if root is None:
        return 0
    cur = root
    return 1 + bt_size(root.left) + bt_size(root.right)


data = sys.stdin.read().split()

n = int(data[0])
k = int(data[-1])
nums = list(map(int, data[1 : 1 + n]))
root = None

for x in nums:
    root = bt_insert(root, x)

print(bt_size(root))
