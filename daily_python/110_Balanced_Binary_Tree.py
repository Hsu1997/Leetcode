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

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        if abs(l - r) > 1:
            self.ans = False
        return max(l, r) + 1
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.ans = True
        self.dfs(root)
        return self.ans

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
        results.append(solution.isBalanced(root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
