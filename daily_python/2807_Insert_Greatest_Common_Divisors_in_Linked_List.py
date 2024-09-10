import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def create_list(nodes: List[int]) -> ListNode :
    if not nodes:
        return None
    head = ListNode(nodes[0])
    curr = head
    for i in range(1, len(nodes)):
        curr.next = ListNode(nodes[i])
        curr = curr.next
    return head

def print_list(head: ListNode) -> None:
    while(head):
        print(head.val, end = ' ')
        head = head.next
    print()

class Solution:
    def GCD(self, a: int, b: int) -> int:
        if a % b == 0:
            return b
        return self.GCD(b, a % b)
    
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = head
        curr = head.next
        while curr:
            prev.next = ListNode(self.GCD(prev.val, curr.val))
            prev.next.next = curr
            prev = curr
            curr = prev.next
        return head
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            head = create_list(nodes)
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
        results.append(solution.insertGreatestCommonDivisors(head))
    for index, result in enumerate(results):
        print(f'Example : ', end = '')
        print_list(result)