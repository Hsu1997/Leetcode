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
    def __init__(self, nodes):
        if not nodes:
            self.root = None
        else:
            self.root = TreeNode(nodes[0])
            i = 1
            n = len(nodes)
            que = deque([self.root])
            while que and i < n:
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
    def dfs_left_first(self, root: TreeNode, level: int):
        if not root:
            return
        self.left_first[root.val] = self.limit
        self.limit = max(level, self.limit)
        self.dfs_left_first(root.left, level+1)
        self.dfs_left_first(root.right, level+1)

    def dfs_right_first(self, root: TreeNode, level: int):
        if not root:
            return
        self.right_first[root.val] = self.limit
        self.limit = max(level, self.limit)
        self.dfs_right_first(root.right, level+1)
        self.dfs_right_first(root.left, level+1)

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        self.left_first = {}
        self.right_first = {}
        self.limit = 0
        self.dfs_left_first(root, 0)
        self.limit = 0
        self.dfs_right_first(root, 0)
        ans = []
        for q in queries:
            ans.append(max(self.left_first.get(q, 0), self.right_first.get(q, 0)))
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            T = Tree(nodes)
            dataset.append((T.root, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for root, queries in dataset:
        results.append(solution.treeQueries(root, queries))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')