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
    def printTree(self):
        print(self.val, end = ' ')
        que = deque([self.left, self.right])
        while que:
            curr = que.popleft()
            if curr:
                print(curr.val, end = ' ')
                que.append(curr.left)
                que.append(curr.right)
            else:
                print(-1, end = ' ')
        print()
        return

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = {}
        children = set()
        for p, c, l in descriptions:
            if p not in nodes:
                nodes[p] = TreeNode(p)
            if c not in nodes:
                nodes[c] = TreeNode(c)
            children.add(c)
            if l == 0:
                nodes[p].right = nodes[c]
            else:
                nodes[p].left = nodes[c]
        for val, node in nodes.items():
            if val not in children:
                return node
        return None
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            descriptions = [list(map(int, description.split(','))) for description in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(descriptions)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for descriptions in dataset:
        results.append(solution.createBinaryTree(descriptions))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : ', end = '')
        result.printTree() if result else print(-1)