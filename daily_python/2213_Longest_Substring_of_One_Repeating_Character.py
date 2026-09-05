import os
import sys
from typing import List

class Node:
    left: int
    right: int
    prefixLen = 1
    suffixLen = 1
    maxLen = 1

class SegmentTree:
    def __init__(self, s: str):
        n = len(s)
        self.n = 1
        while self.n < n:
            self.n *= 2
        self.left = [0] * (2 * self.n)
        self.right = [0] * (2 * self.n)
        self.leftChar = [' '] * (2 * self.n)
        self.rightChar = [' '] * (2 * self.n)
        self.prefixLen = [0] * (2 * self.n)
        self.suffixLen = [0] * (2 * self.n)
        self.maxLen = [0] * (2 * self.n)
        for i in range(n):
            self.left[self.n + i] = i
            self.right[self.n + i] = i
            self.leftChar[self.n + i] = s[i]
            self.rightChar[self.n + i] = s[i]
            self.prefixLen[self.n + i] = 1
            self.suffixLen[self.n + i] = 1
            self.maxLen[self.n + i] = 1
        for i in range(self.n - 1, 0, -1):
            self.update(i)

    def update(self, idx: int) -> None:
        leftNodeIdx = idx * 2
        rightNodeIdx = idx * 2 + 1
        self.left[idx] = self.left[leftNodeIdx]
        self.right[idx] = self.right[rightNodeIdx]
        self.leftChar[idx] = self.leftChar[leftNodeIdx]
        self.rightChar[idx] = self.rightChar[rightNodeIdx]
        self.prefixLen[idx] = self.prefixLen[leftNodeIdx]
        if self.right[leftNodeIdx] - self.left[leftNodeIdx] + 1 == self.prefixLen[leftNodeIdx] and self.leftChar[leftNodeIdx] == self.leftChar[rightNodeIdx]:
            self.prefixLen[idx] = self.right[leftNodeIdx] - self.left[leftNodeIdx] + 1 + self.prefixLen[rightNodeIdx]
        self.suffixLen[idx] = self.suffixLen[rightNodeIdx]
        if self.right[rightNodeIdx] - self.left[rightNodeIdx] + 1 == self.suffixLen[rightNodeIdx] and self.rightChar[rightNodeIdx] == self.rightChar[leftNodeIdx]:
            self.suffixLen[idx] = self.right[rightNodeIdx] - self.left[rightNodeIdx] + 1 + self.suffixLen[leftNodeIdx]
        self.maxLen[idx] = max(self.prefixLen[leftNodeIdx], self.suffixLen[rightNodeIdx], self.maxLen[leftNodeIdx], self.maxLen[rightNodeIdx])
        if self.rightChar[leftNodeIdx] == self.leftChar[rightNodeIdx]:
            self.maxLen[idx] = max(self.maxLen[idx], self.suffixLen[leftNodeIdx] + self.prefixLen[rightNodeIdx])

    def edit(self, idx: int, char: chr) -> None:
        idx += self.n
        self.leftChar[idx] = char
        self.rightChar[idx] = char
        idx //= 2
        while idx:
            self.update(idx)
            idx //= 2

    def currMax(self) -> int:
        return self.maxLen[1]
    
class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        T = SegmentTree(s)
        ans = []
        for q in range(len(queryCharacters)):
            T.edit(queryIndices[q], queryCharacters[q])
            ans.append(T.currMax())
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            queryCharacters = lines[1].split('=')[1].strip()[1:-2]
            queryIndices = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((s, queryCharacters, queryIndices))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, queryCharacters, queryIndices in dataset:
        results.append(solution.longestRepeating(s, queryCharacters, queryIndices))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')