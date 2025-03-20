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
    def __init__(self, nodes: List[int]):
        self.root = TreeNode(nodes[0]) if nodes else None
        que = deque([self.root])
        i = 1
        n = len(nodes)
        while i < n:
            curr = que.popleft()
            if i < n and nodes[i] is not None:
                curr.left = TreeNode(nodes[i])
                que.append(curr.left)
            i += 1
            if i < n and nodes[i] is not None:
                curr.right = TreeNode(nodes[i])
                que.append(curr.right)
            i += 1
    def printTree(self):
        print_queue = []
        que = deque([self.root])
        while que:
            curr = que.popleft()
            if curr:
                print_queue.append(curr.val)
                que.append(curr.left)
                que.append(curr.right)
            else:
                print_queue.append(None)
        while print_queue and print_queue[-1] == None:
            print_queue.pop()
        return print_queue

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        que = deque([root])
        level = 0
        while que:
            k = len(que)
            curr_level = []
            for _ in range(k):
                curr = que.popleft()
                if curr.left:
                    que.append(curr.left)
                    que.append(curr.right)
                    if level % 2 == 0:
                        curr_level.append(curr.left)
                        curr_level.append(curr.right)
            if level % 2 == 0:
                left = 0
                right = len(curr_level) - 1
                while left < right:
                    curr_level[left].val, curr_level[right].val = curr_level[right].val, curr_level[left].val
                    left += 1
                    right -= 1
            level += 1
        return root

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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    for index, nodes in enumerate(dataset):
        T = Tree(nodes)
        solution.reverseOddLevels(T.root)
        print(f'Example {index + 1} : {T.printTree()}')