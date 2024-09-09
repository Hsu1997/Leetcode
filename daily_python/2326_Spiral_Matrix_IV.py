import os
import sys
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def Create_list(nodes: List[int])-> ListNode:
    if not nodes:
        return None
    head = ListNode(nodes[0])
    temp = head
    for i in range(1, len(nodes)):
        temp.next = ListNode(nodes[i])
        temp = temp.next
    return head

class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        table = [[-1 for _ in range(n)] for _ in range(m)]
        dir = [[0,1],[1,0],[0,-1],[-1,0]]
        d = 0
        x = y = 0
        while head:
            table[x][y] = head.val
            new_x = x + dir[d][0]
            new_y = y + dir[d][1]
            if new_x < 0 or new_x >= m or new_y < 0 or new_y >= n or table[new_x][new_y] != -1:
                d = (d + 1) % 4
            x += dir[d][0]
            y += dir[d][1]
            head = head.next
        return table
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            nodes = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            head = Create_list(nodes)
            dataset.append((m, n, head))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n, head in dataset:
        results.append(solution.spiralMatrix(m, n, head))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')