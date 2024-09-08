import os
import sys
from typing import List, Optional
import queue

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def create_list(nodes: List[int])-> ListNode:
    if not nodes:
        return None
    head = ListNode(nodes[0])
    curr = head
    for i in range(1, len(nodes)):
        curr.next = ListNode(nodes[i])
        curr = curr.next
    return head

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def create_tree(nodes: List[int])-> TreeNode:
    if not nodes:
        return None
    n = len(nodes)
    root = TreeNode(nodes[0])
    i = 1
    que = queue.Queue()
    que.put(root)
    while i < n and que:
        curr = que.get()
        if i < n and nodes[i] != -1:
            curr.left = TreeNode(nodes[i])
            que.put(curr.left)
        i += 1
        if i < n and nodes[i] != -1:
            curr.right = TreeNode(nodes[i])
            que.put(curr.right)
        i += 1
    return root

class Solution:
    def dfs(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if head is None:
            return True
        if root is None:
            return False
        if head.val == root.val:
            return self.dfs(head.next, root.left) or self.dfs(head.next, root.right)
        return False
        
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        if self.dfs(head, root):
            return True
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            l = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            n = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            head = create_list(l)
            root = create_tree(n)
            dataset.append((head, root))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for head, root in dataset:
        results.append(solution.isSubPath(head, root))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')