import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_linked_list(nodes):
    if not nodes:
        return None
    root = ListNode(nodes[0])
    temp = root
    for val in nodes[1:]:
        temp.next = ListNode(val)
        temp = temp.next
    return root

def print_list(root: Optional[ListNode]):
    while root:
        print(root.val, end = ' ')
        root = root.next
    print()

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        remove = set(nums)
        pseudo = ListNode(0, head)
        temp = pseudo
        ptr = head
        while ptr:
            if ptr.val not in remove:
                temp.next = ptr
                temp = temp.next
            ptr = ptr.next
        temp.next = None
        return pseudo.next
    
def readDataSet(filename):
    dataset = []
    with open(filename) as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            nodes = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((nums, nodes))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, nodes in dataset:
        head = create_linked_list(nodes)
        results.append(solution.modifiedList(nums, head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : ', end = '')
        print_list(result)