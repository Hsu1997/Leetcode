import sys
import os
from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_tree(root: TreeNode) -> None:
    que = deque([root])
    while que:
        curr = que.popleft()
        if not curr:
            print(-1, end = ' ')
        else:
            print(curr.val, end = ' ')
            que.append(curr.left)
            que.append(curr.right)
    print()

class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        n = len(preorder)
        post_val_to_pos = [0] * (n + 1)
        for i in range(n):
            post_val_to_pos[postorder[i]] = i
        return self.create_tree(preorder, postorder, post_val_to_pos, 0, n-1, 0, n-1)
    
    def create_tree(self, preorder: List[int], postorder: List[int], post_val_to_pos: List[int], pre_start: int, pre_end: int, post_start: int, post_end: int) -> Optional[TreeNode]:
        if pre_start > pre_end or post_start > post_end:
            return None
        root = TreeNode(preorder[pre_start])
        if pre_start == pre_end:
            return root
        left_root_val = preorder[pre_start + 1]
        left_root_pos = post_val_to_pos[left_root_val]
        left_tree_size = left_root_pos - post_start + 1
        root.left = self.create_tree(preorder, postorder, post_val_to_pos, pre_start + 1, pre_start + left_tree_size, post_start, left_root_pos)
        root.right = self.create_tree(preorder, postorder, post_val_to_pos, pre_start + left_tree_size + 1, pre_end, left_root_pos + 1, post_end - 1)
        return root
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            preorder = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            postorder = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((preorder, postorder))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for preorder, postorder in dataset:
        results.append(solution.constructFromPrePost(preorder, postorder))
    for index, result in enumerate(results):
        print(f'Example {index+1} :')
        print_tree(result)