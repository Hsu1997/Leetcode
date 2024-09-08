import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_linker_list(nodes: List[int])-> ListNode:
    if nodes is None:
        return None
    root = ListNode(nodes[0])
    temp = root
    for i in range(1, len(nodes)):
        temp.next = ListNode(nodes[i])
        temp = temp.next
    return root

def print_linked_list(root: ListNode)-> None:
    while root:
        print(root.val, end = ' ')
        root = root.next
    print()
    return

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        count = 0
        temp = head
        while temp:
            count += 1
            temp = temp.next
        temp = head
        ans = [None] * k
        average = count // k
        add_one = count % k
        for i in range(k):
            if average == 0 and i >= add_one:
                continue
            ans[i] = temp
            curr_count = 1
            while curr_count < average + (i < add_one):
                temp = temp.next
                curr_count += 1
            ptr = temp
            temp = temp.next
            ptr.next = None
        return ans
    
def readDataSeet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1][:-1])
            head = create_linker_list(nodes)
            dataset.append((head, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSeet(filename)
    results = []
    solution = Solution()
    for head, k in dataset:
        results.append(solution.splitListToParts(head, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : ')
        for r in result:
            print_linked_list(r)