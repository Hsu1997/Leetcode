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

class Tree:
    def __init__(self, nodes):
        if not nodes:
            self.root = None
            return
        self.root = TreeNode(nodes[0])
        n = len(nodes)
        i = 1
        que = deque([self.root])
        while que:
            curr = que.popleft()
            if i < n and nodes[i] != -1:
                curr.left = TreeNode(nodes[i])
                que.append(curr.left)
            i += 1
            if i < n and nodes[i] != -1:
                curr.right = TreeNode(nodes[i])
                que.append(curr.right)
            i += 1

class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.s = set()
        root.val = 0
        self.recursion(root)
    
    def recursion(self, node: Optional[TreeNode]):
        if not node:
            return
        self.s.add(node.val)
        if node.left:
            node.left.val = node.val * 2 + 1
            self.recursion(node.left)
        if node.right:
            node.right.val = node.val * 2 + 2
            self.recursion(node.right)

    def find(self, target: int) -> bool:
        return target in self.s

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
            query = list(map(int,lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((nodes, query))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for nodes, query in dataset:
        result = []
        T = Tree(nodes)
        F = FindElements(T.root)
        for q in query:
            result.append(F.find(q))
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
