import os
import sys
from typing import List, Optional
import queue

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def create_tree(nodes: List[int])-> TreeNode:
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    que = queue.Queue()
    que.put(root)
    index = 1
    n = len(nodes)
    while index < n and not que.empty():
        temp = que.get()
        if index < n and nodes[index] != -1:
            temp.left = TreeNode(nodes[index])
            que.put(temp.left)
        index += 1
        if index < n and nodes[index] != -1:
            temp.right = TreeNode(nodes[index])
            que.put(temp.right)
        index += 1
    return root

class Solution:
    def traversal(self, root: TreeNode)-> None:
        if not root:
            return
        self.traversal(root.left)
        self.traversal(root.right)
        self.postorder.append(root.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.postorder = []
        self.traversal(root)
        return self.postorder

def readDataSet(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nodes = lines[0].split('=')[1].strip()[1:-2]
            if nodes:
                nodes = nodes.split(',')
                data = [int(i) for i in nodes]
            else:
                data = []
            dataset.append(data)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        results.append(solution.postorderTraversal(create_tree(nodes)))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
