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
    def count_swaps(self, nums: List[int])-> int:
        sorted = nums.copy()
        sorted.sort()
        n = len(nums)
        swaps = 0
        pos = {}
        for i in range(n):
            pos[nums[i]] = i
        for i in range(n):
            if nums[i] != sorted[i]:
                p = pos[sorted[i]]
                pos[nums[i]] = p
                nums[i], nums[p] = nums[p], nums[i]
                swaps += 1
        return swaps
    
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        que = deque()
        que.append(root)
        totalswaps = 0
        while que:
            curr_level_size = len(que)
            curr_level_nums = []
            for _ in range(curr_level_size):
                curr_node = que.popleft()
                curr_level_nums.append(curr_node.val)
                if curr_node.left:
                    que.append(curr_node.left)
                if curr_node.right:
                    que.append(curr_node.right)
            totalswaps += self.count_swaps(curr_level_nums)
        return totalswaps

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
        results.append(solution.minimumOperations(root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    