import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self, nodes: Optional[List[int]]):
        if not nodes:
            self.head = None
        else:
            self.head = ListNode(nodes[0])
            curr = self.head
            for node in nodes[1:]:
                curr.next = ListNode(node)
                curr = curr.next

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        ans = 0
        while head:
            ans = ans * 2 + head.val
            head = head.next
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            l = LinkedList(nodes)
            dataset.append(l)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for l in dataset:
        results.append(solution.getDecimalValue(l.head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')