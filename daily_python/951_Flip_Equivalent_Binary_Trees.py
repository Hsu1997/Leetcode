import os
import sys
from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Tree:
    def __init__(self, nodes: List[int]):
        if not nodes:
            self.root = None
        else:
            self.root = TreeNode(nodes[0])
            i = 1
            n = len(nodes)
            que = deque([self.root])
            while i < n and que:
                curr = que.popleft()
                if i < n and nodes[i] != -1:
                    curr.left = TreeNode(nodes[i])
                    que.append(curr.left)
                i += 1
                if i < n and nodes[i] != -1:
                    curr.right = TreeNode(nodes[i])
                    que.append(curr.right)
                i += 1

class Solution:
    def dfs(self, root: TreeNode, relationship):
        if not root:
            return
        relationship.append((root.val, root.left.val if root.left else -1))
        relationship.append((root.val, root.right.val if root.right else -1))
        self.dfs(root.left, relationship)
        self.dfs(root.right, relationship)

    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        relationship1 = []
        relationship2 = []
        self.dfs(root1, relationship1)
        self.dfs(root2, relationship2)
        if len(relationship1) != len(relationship2):
            return False
        relationship1.sort()
        relationship2.sort()
        for i in range(len(relationship1)):
            if relationship1[i] != relationship2[i]:
                return False
        return True
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes1 = lines[0].split('=')[1].strip()[1:-2]
            nodes2 = lines[1].split('=')[1].strip()[1:-2]
            if nodes1:
                root1 = Tree(list(map(int, nodes1.split(',')))).root
            else:
                root1 = Tree([]).root
            if nodes2:
                root2 = Tree(list(map(int, nodes2.split(',')))).root
            else:
                root2 = Tree([]).root
            dataset.append((root1, root2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for root1, root2 in dataset:
        results.append(solution.flipEquiv(root1, root2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')