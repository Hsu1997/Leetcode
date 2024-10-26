import os
import sys
from typing import List

class Node:
    def __init__(self):
        self.child = {}
        self.is_word = False
        self.s = ""

class Trie:
    def __init__(self):
        self.root = Node()
    def add_word(self, word):
        if not word or word[0] != '/':
            return
        curr = self.root
        i = 1
        n = len(word)
        while i < n:
            start = i
            while i < n and word[i] != '/':
                i += 1
            substr = word[start:i]
            if substr not in curr.child:
                curr.child[substr] = Node()
            curr = curr.child[substr]
            i += 1
        curr.is_word = True
        curr.s = word
        
class Solution:
    def bfs(self, node: Node):
        if node.is_word:
            self.ans.append(node.s)
            return
        for n in node.child.values():
            self.bfs(n)

    def removeSubfolders(self, folder: List[str]) -> List[str]:
        T = Trie()
        for s in folder:
            T.add_word(s)
        self.ans = []
        self.bfs(T.root)
        return self.ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            floder = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(floder)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for folder in dataset:
        results.append(solution.removeSubfolders(folder))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
