import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        ans = [-1, -1]
        if not head or not head.next:
            return ans
        firstCritical = -1
        prevCritical = -1
        prev = head
        curr = head.next
        idx = 1
        midDistance = 100001
        while curr.next:
            if prev.val < curr.val > curr.next.val or prev.val > curr.val < curr.next.val:
                if firstCritical == -1:
                    firstCritical = idx
                else:
                    midDistance = min(midDistance, idx - prevCritical)
                prevCritical = idx
            prev = curr
            curr = curr.next
            idx += 1
        if midDistance != 100001:
            ans = [midDistance, prevCritical - firstCritical]
        return ans

def createList(nodes: List[int]) -> ListNode:
    if not nodes:
        return None
    head = ListNode(nodes[0])
    curr = head
    for v in nodes[1:]:
        curr.next = ListNode(v)
        curr = curr.next
    return head

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            head = createList(nodes)
            dataset.append(head)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for head in dataset:
        results.append(solution.nodesBetweenCriticalPoints(head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')