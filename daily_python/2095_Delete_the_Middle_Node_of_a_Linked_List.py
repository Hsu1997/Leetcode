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
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        pseudo = ListNode(0, head)
        ptr = pseudo
        n = 0
        while ptr.next:
            n += 1
            ptr = ptr.next
        n //= 2
        ptr = pseudo
        while n:
            n -= 1
            ptr = ptr.next
        ptr.next = ptr.next.next
        return pseudo.next

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
        results.append(solution.deleteMiddle(L(nodes).head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : ', end = '')
        ptr = result
        while ptr:
            print(ptr.val, end = ' ')
            ptr = ptr.next
        print()