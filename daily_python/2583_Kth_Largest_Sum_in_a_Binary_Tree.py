import os
import sys
import heapq
from collections import deque
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        pq = []
        que = deque()
        que.append(root)
        while que:
            n = len(que)
            curr_sum = 0
            for i in range(n):
                temp = que.popleft()
                curr_sum += temp.val
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
            pq.append(curr_sum)

        if len(pq) < k:
            return -1
        heapq.heapify(pq)
        for i in range(len(pq) - k):
            heapq.heappop(pq)
        return heapq.heappop(pq)
    
def create_tree(nodes: Optional[List[int]])-> TreeNode:
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    que = deque([root])
    i = 1
    n = len(nodes)
    while que and i < n:
        temp = que.popleft()
        if i < n and nodes[i] != -1:
            temp.left = TreeNode(nodes[i])
            que.append(temp.left)
        i += 1
        if i < n and nodes[i] != -1:
            temp.right = TreeNode(nodes[i])
            que.append(temp.right)
        i += 1
    return root

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            root = create_tree(nodes)
            dataset.append((root, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for root, k in dataset:
        results.append(solution.kthLargestLevelSum(root, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')