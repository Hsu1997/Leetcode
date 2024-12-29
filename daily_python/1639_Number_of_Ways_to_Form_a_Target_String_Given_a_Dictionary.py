import os
import sys
from typing import List

class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.k = 0
        self.mod = 1e9 + 7
        self.memo = []
        self.freq = []
    def helper(self, i, j, target):
        if j == self.n:
            return 1
        if i == self.m:
            return 0
        if self.memo[i][j] != -1:
            return self.memo[i][j]
        target_char = ord(target[j]) - ord('a')
        take = (self.freq[i][target_char]) * self.helper(i+1, j+1, target) % self.mod
        not_take = self.helper(i+1, j, target)
        self.memo[i][j] = int((take + not_take) % self.mod)
        return self.memo[i][j]
    
    def numWays(self, words: List[str], target: str) -> int:
        self.m = len(words[0])
        self.n = len(target)
        self.k = len(words)
        if self.n > self.m:
            return 0
        self.memo = [[-1] * self.n for _ in range(self.m)]
        self.freq = [[0] * 26 for _ in range(self.m)]
        for i in range(self.m):
            for word in words:
                self.freq[i][ord(word[i]) - ord('a')] += 1
        return self.helper(0, 0, target)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            target = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((words, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, target in dataset:
        results.append(solution.numWays(words, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')