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
    
    def create_tree(self, nodes: Optional[List[int]]):
        if not nodes:
            return None
        root = TreeNode(nodes[0])
        i = 1
        que = deque([root])
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
    
    def print_tree(self):
        if not self:
            return
        que = deque([self])
        while que:
            curr = que.popleft()
            if not curr:
                print(-1, end = ' ')
            else:
                print(curr.val, end = ' ')
                que.append(curr.left)
                que.append(curr.right)
        print()

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        level_sum = []
        que = deque([root])
        while que:
            curr_level_sum = 0
            level_size = len(que)
            for i in range(level_size):
                curr = que.popleft()
                curr_level_sum += curr.val
                if curr.left:
                    que.append(curr.left)
                if curr.right:
                    que.append(curr.right)
            level_sum.append(curr_level_sum)
        que.append(root)
        root.val = 0
        curr_level = 1
        while que:
            level_size = len(que)
            for i in range(level_size):
                curr = que.popleft()
                curr_total = 0
                if curr.left:
                    curr_total += curr.left.val
                    que.append(curr.left)
                if curr.right:
                    curr_total += curr.right.val
                    que.append(curr.right)
                if curr.left:
                    curr.left.val = level_sum[curr_level] - curr_total
                if curr.right:
                    curr.right.val = level_sum[curr_level] - curr_total
            curr_level += 1
        return root

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            root = TreeNode().create_tree(nodes)
            dataset.append(root)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for root in dataset:
        results.append(solution.replaceValueInTree(root))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : ')
        result.print_tree()