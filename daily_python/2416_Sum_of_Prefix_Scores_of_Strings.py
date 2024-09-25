import os
import sys
from typing import List

class Node:
    def __init__(self):
        self.child = [None] * 26
        self.cnt = 0

class Trie:
    def __init__(self):
        self.root = Node()
    def add_word(self, word):
        curr = self.root
        for c in word:
            if not curr.child[ord(c) - ord('a')]:
                curr.child[ord(c) - ord('a')] = Node()
            curr = curr.child[ord(c) - ord('a')]
            curr.cnt += 1
    def cal_score(self, word):
        ans = 0
        curr = self.root
        for c in word:
            curr = curr.child[ord(c) - ord('a')]
            ans += curr.cnt
        return ans

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        T = Trie()
        for s in words:
            T.add_word(s)
        results = []
        for word in words:
            results.append(T.cal_score(word))
        return results
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            dataset.append(words)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words in dataset:
        results.append(solution.sumPrefixScores(words))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')