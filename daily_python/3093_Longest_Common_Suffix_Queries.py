import os
import sys
from typing import List

class Trie:
    def __init__(self):
        self.total = 1
        self.t = [[-1] * 26]
        self.minIdx = [500002]
        self.minLen = [500002]
    def insert(self, s: str, id: int):
        n = len(s)
        if n < self.minLen[0]:
            self.minIdx[0] = id
            self.minLen[0] = n
        curr = 0
        for i in range(n-1, -1, -1):
            c = ord(s[i]) - ord('a')
            if self.t[curr][c] == -1:
                self.t[curr][c] = self.total
                self.t.append([-1] * 26)
                self.minIdx.append(500002)
                self.minLen.append(500002)
                self.total += 1
            curr = self.t[curr][c]
            if n < self.minLen[curr]:
                self.minIdx[curr] = id
                self.minLen[curr] = n
    def query(self, s: str):
        n = len(s)
        curr = 0
        for i in range(n-1, -1, -1):
            c = ord(s[i]) - ord('a')
            if self.t[curr][c] == -1:
                break
            curr = self.t[curr][c]
        return self.minIdx[curr]
            
class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        T = Trie()
        for id, s in enumerate(wordsContainer):
            T.insert(s, id)
        ans = []
        for s in wordsQuery:
            ans.append(T.query(s))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            wordsContainer = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            wordsQuery = list(lines[1].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((wordsContainer, wordsQuery))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for wordsContainer, wordsQuery in dataset:
        results.append(solution.stringIndices(wordsContainer, wordsQuery))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')