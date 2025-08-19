import os
import sys
from typing import List
from collections import defaultdict

class Node:
    def __init__(self):
        self.serial = ""
        self.children = {}

class Trie:
    def __init__(self):
        self.root = Node()
        self.freq = defaultdict(int)

    def add_folder(self, path):
        curr = self.root
        for p in path:
            if p not in curr.children:
                curr.children[p] = Node()
            curr = curr.children[p]

    def construct_subfolder(self, curr):
        for name, child in sorted(curr.children.items()):
            self.construct_subfolder(child)
            curr.serial += "(" + name + child.serial + ")"
        if curr.serial != "":
            self.freq[curr.serial] += 1

    def find_unique_folder(self):
        ans = []
        for name, child in self.root.children.items():
            curr_path = [name]
            self.dfs(child, curr_path, ans)
        return ans

    def dfs(self, node, curr_path, ans):
        if node.serial != "" and self.freq[node.serial] > 1:
            return
        ans.append(list(curr_path))
        for name, child in node.children.items():
            curr_path.append(name)
            self.dfs(child, curr_path, ans)
            curr_path.pop()

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        T = Trie()
        for path in paths:
            T.add_folder(path)
        T.construct_subfolder(T.root)
        return T.find_unique_folder()
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            paths = [list(path.split('","')) for path in lines[0].split('=')[1].strip()[3:-4].split('"},{"')]
            dataset.append(paths)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for paths in dataset:
        results.append(solution.deleteDuplicateFolder(paths))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')