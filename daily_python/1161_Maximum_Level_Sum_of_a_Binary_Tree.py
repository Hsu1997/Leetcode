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

def buildTree(nodes: List[Optional[int]])-> Optional[TreeNode]:
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    que = deque([root])
    i = 1
    while que and i < len(nodes):
        curr = que.popleft()
        if i < len(nodes) and nodes[i] != 100001:
            curr.left = TreeNode(nodes[i])
            que.append(curr.left)
        i += 1
        if i < len(nodes) and nodes[i] != 100001:
            curr.right = TreeNode(nodes[i])
            que.append(curr.right)
        i += 1
    return root

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ans = 0
        maxSum = float('-inf')
        que = deque([root])
        level = 0
        while que:
            level += 1
            currSum = 0
            n = len(que)
            for _ in range(n):
                temp = que.popleft()
                currSum += temp.val
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
            if currSum > maxSum:
                ans = level
                maxSum = currSum
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nodes)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        results.append(solution.maxLevelSum(buildTree(nodes)))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')