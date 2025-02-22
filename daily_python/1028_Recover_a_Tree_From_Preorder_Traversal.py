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
    def print(self):
        if not self:
            print("Empty Tree")
            return
        que = deque([self])
        result = []
        while que:
            curr = que.popleft()
            if curr:
                result.append(curr.val)
                que.append(curr.left)
                que.append(curr.right)
            else:
                result.append("None")
        print(result)

class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        n = len(traversal)
        nodes = []
        temp = ""
        depth = 0
        i = 0
        while i < n:
            if traversal[i] == '-':
                depth += 1
                i += 1
            else:
                while i < n and traversal[i] != '-':
                    temp += traversal[i]
                    i += 1
                nodes.append((int(temp), depth))
                temp = ""
                depth = 0
        root = TreeNode(nodes[0][0])
        n = len(nodes)
        sta = [root]
        for value, depth in nodes[1:]:
            if depth == len(sta):
                curr = sta[-1]
                curr.left = TreeNode(value)
                sta.append(curr.left)
            else:
                while len(sta) > depth:
                    sta.pop()
                curr = sta[-1]
                curr.right = TreeNode(value)
                sta.append(curr.right)
        return root
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            traversal = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(traversal)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for traversal in dataset:
        results.append(solution.recoverFromPreorder(traversal))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result.print()}')
