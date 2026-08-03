import os
import sys
from typing import List

class Solution:
    def dp(self, start: int, stoneValue: List[int]) -> int:
        if start >= self.n:
            return 0
        if self.memo[start] != -10**8:
            return self.memo[start]
        curr = 0
        res = float('-inf')
        for i in range(start, min(self.n, start + 3)):
            curr += stoneValue[i]
            res = max(res, curr - self.dp(i + 1, stoneValue))
        self.memo[start] = res
        return res
    
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        self.n = len(stoneValue)
        self.memo = [-10**8] * self.n
        self.dp(0, stoneValue)
        if self.memo[0] == 0:
            return 'Tie'
        return 'Alice' if self.memo[0] > 0 else 'Bob'

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            stoneValue = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(stoneValue)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for stoneValue in dataset:
        results.append(solution.stoneGameIII(stoneValue))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')