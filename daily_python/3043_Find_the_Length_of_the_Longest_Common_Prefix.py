import os
import sys
from typing import List

class Node:
    def __init__(self):
        self.child = [None] * 10

class Trie:
    def __init__(self):
        self.root = Node()
    def add_word(self, i):
        node = self.root
        i = str(i)
        for c in i:
            if not node.child[int(c)]:
                node.child[int(c)] = Node()
            node = node.child[int(c)]
    def find_longest_len(self, i):
        i = str(i)
        node = self.root
        common_len = 0
        for c in i:
            if not node.child[int(c)]:
                return common_len
            node = node.child[int(c)]
            common_len += 1
        return common_len

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        T = Trie()
        for i in arr1:
            T.add_word(i)
        ans = 0
        for i in arr2:
            ans = max(ans, T.find_longest_len(i))
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            arr2 = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((arr1, arr2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr1, arr2 in dataset:
        results.append(solution.longestCommonPrefix(arr1, arr2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')