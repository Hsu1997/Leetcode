import sys
import os
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class L:
    def __init__(self, nodes: List[int]):
        pseudo = ListNode()
        ptr = pseudo
        for i in nodes:
            ptr.next = ListNode(i)
            ptr = ptr.next
        self.head = pseudo.next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        ptr = head
        n = 1
        while ptr.next:
            ptr = ptr.next
            n += 1
        ptr.next = head
        c = n - 1 - (k % n)
        ptr = head
        for _ in range(c):
            ptr = ptr.next
        head = ptr.next
        ptr.next = None
        return head

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            element = lines[0].split('=')[1].strip()[1:-2]
            nodes = list(map(int, element.split(','))) if element else []
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nodes, k))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes, k in dataset:
        l = L(nodes)
        results.append(solution.rotateRight(l.head, k))
    for index, result in enumerate(results):
        print(f'Example {index+1} : ', end = '')
        ptr = result
        while ptr:
            print(ptr.val, end = ' ')
            ptr = ptr.next
        print()