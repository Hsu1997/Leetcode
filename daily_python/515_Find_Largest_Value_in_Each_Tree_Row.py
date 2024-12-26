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

def create_tree(nodes: List[Optional[int]])-> Optional['TreeNode']:
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    que = deque()
    que.append(root)
    i = 1
    n = len(nodes)
    while i < n:
        curr = que.popleft()
        if i < n and nodes[i] != -1:
            curr.left = TreeNode(nodes[i])
            que.append(curr.left)
        i += 1
        if i < n and nodes[i] != -1:
            curr.right = TreeNode(nodes[i])
            que.append(curr.right)
        i += 1
    return root

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if not root:
            return ans
        que = deque()
        que.append(root)
        while que:
            n = len(que)
            curr_max = float('-INF')
            for _ in range(n):
                curr = que.popleft()
                curr_max = max(curr_max, curr.val)
                if curr.left:
                    que.append(curr.left)
                if curr.right:
                    que.append(curr.right)
            ans.append(curr_max)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            root = create_tree(nodes)
            dataset.append(root)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for root in dataset:
        results.append(solution.largestValues(root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    