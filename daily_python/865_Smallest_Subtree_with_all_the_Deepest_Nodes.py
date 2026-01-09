import os
import sys
from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(nodes: List[Optional[int]])-> Optional[TreeNode]:
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    que = deque([root])
    i = 1
    while que and i < len(nodes):
        curr = que.popleft()
        if i < len(nodes) and nodes[i] != 100001:
            curr.left = TreeNode(nodes[i])
            que.append(curr.left)
        i += 1
        if i < len(nodes) and nodes[i] != 100001:
            curr.right = TreeNode(nodes[i])
            que.append(curr.right)
        i += 1
    return root

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        depth = {None : -1}
        def dfs(node, parent):
            if node:
                depth[node] = depth[parent] + 1
                dfs(node.left, node)
                dfs(node.right, node)
        dfs(root, None)
        max_depth = max(depth.values())
        def answer(node):
            if not node or depth[node] == max_depth:
                return node
            L, R = answer(node.left), answer(node.right)
            return node if L and R else L or R
        return answer(root)

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
        results.append(solution.subtreeWithAllDeepest(buildTree(nodes)).val)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')