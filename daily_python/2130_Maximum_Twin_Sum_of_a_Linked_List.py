import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class L:
    def __init__(self, nodes: Optional[List[int]]):
        self.head = None if not nodes else ListNode(nodes[0])
        ptr = self.head
        for i in range(1, len(nodes)):
            ptr.next = ListNode(nodes[i])
            ptr = ptr.next

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        v = []
        ptr = head
        while ptr:
            v.append(ptr.val)
            ptr = ptr.next
        n = len(v)
        ans = 0
        for i in range(n // 2):
            ans = max(ans, v[i] + v[n-1-i])
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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        results.append(solution.pairSum(L(nodes).head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')