import sys


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def bt_insert(root, val):
    if root is None:
        return Node(val)
    if val < root.data:
        root.left = bt_insert(root.left, val)
    else:
        root.right = bt_insert(root.right, val)
    return root


def check(root, s):
    cur = root
    for c in s:
        if c == "R":
            cur = cur.right
        else:
            cur = cur.left
        if cur is None:
            return "NO"
    return "YES"


data = sys.stdin.read().split()


n, m = map(int, data[:2])


nums = list(map(int, data[2 : 2 + n]))


queries = data[2 + n :]


root = None
for x in nums:
    root = bt_insert(root, x)

# проверяем запросы
for s in queries:
    print(check(root, s))
