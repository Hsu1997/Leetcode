import os
import sys
from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def createTree(nodes: List[Optional[int]]) -> Optional[TreeNode]:
    if nodes == []:
        return None
    root = TreeNode(nodes[0])
    n = len(nodes)
    idx = 1
    q = deque([root])
    while idx < n and q:
        curr = q.popleft()
        if idx < n and nodes[idx] is not None:
            curr.left = TreeNode(nodes[idx])
            q.append(curr.left)
        idx += 1
        if idx < n and nodes[idx] is not None:
            curr.right = TreeNode(nodes[idx])
            q.append(curr.right)
        idx += 1
    return root

def printTree(root: TreeNode) -> None:
    q = deque([root])
    while q:
        curr = q.popleft()
        if curr is None:
            print(-1, end = ' ')
        else:
            print(curr.val, end = ' ')
            q.append(curr.left)
            q.append(curr.right)
    print()

class Solution:
    def inorder_traversal(self, root: TreeNode) -> None:
        if not root:
            return
        self.inorder_traversal(root.left)
        self.inorder.append(root.val)
        self.inorder_traversal(root.right)

    def create_BST(self, left: int, right: int) -> TreeNode:
        if left > right:
            return None
        mid = left + (right - left) // 2
        return TreeNode(self.inorder[mid], self.create_BST(left, mid - 1), self.create_BST(mid + 1, right))
    
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.inorder = []
        self.inorder_traversal(root)
        n = len(self.inorder)
        return self.create_BST(0, n-1)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            node = lines[0].split('=')[1].strip()[1:-2]
            nodes = [int(x) if x != 'null' else None for x in node.split(',')] if node else []
            dataset.append(nodes)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        root = createTree(nodes)
        results.append(solution.balanceBST(root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : ', end = '')
        printTree(result)
