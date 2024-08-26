import os
import sys
from typing import List, Optional
import queue

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

def create_tree(nodes: List[int])-> Optional['Node']:
    if not nodes:
        return None
    n = len(nodes)
    root = Node(nodes[0])
    index = 2
    que = queue.Queue()
    que.put(root)
    while index < n and not que.empty():
        temp = que.get()
        _children = []
        while index < n and nodes[index] != -1:
            _children.append(Node(nodes[index]))
            que.put(_children[-1])
            index += 1
        temp.children = _children
        index += 1
    return root

class Solution:
    def traversal(self, node: 'Node')-> None:
        if not node:
            return
        if node.children:
            for child in node.children:
                self.traversal(child)
        self.path.append(node.val)
    def postorder(self, root: 'Node') -> List[int]:
        self.path = []
        self.traversal(root)
        return self.path
    
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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nodes in dataset:
        node = create_tree(nodes)
        results.append(solution.postorder(node))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')