import os
import sys
from typing import List, Optional, Tuple
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Tree:
    def __init__(self, nodes: List[Optional[int]]):
        if not nodes:
            self.root = None
            return
        n = len(nodes)
        i = 1
        self.root = TreeNode(nodes[0])
        que = deque([self.root])
        while i < n and que:
            curr = que.popleft()
            if i < n and nodes[i] is not None:
                curr.left = TreeNode(nodes[i])
                que.append(curr.left)
            i += 1
            if i < n and nodes[i] is not None:
                curr.right = TreeNode(nodes[i])
                que.append(curr.right)
            i += 1

class Solution:
    def dfs(self, node: Optional[TreeNode], depth: int) -> Tuple[Optional[TreeNode], int]:
        if not node:
            return (None, 0)
        left = self.dfs(node.left, depth + 1)
        right = self.dfs(node.right, depth + 1)
        if left[1] > right[1]:
            return left
        elif left[1] < right[1]:
            return right
        else:
            return (node, max(depth, left[1]))
        
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root, 1)[0]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = [None if node == 'None' else int(node) for node in lines[0].split('=')[1].strip()[1:-2].split(',')]
            dataset.append(nodes)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        root = Tree(nodes).root
        results.append(solution.lcaDeepestLeaves(root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result.val}')