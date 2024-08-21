import os
import sys
from typing import List

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = [[[-1 for _ in range(n + 1)] for _ in range(n)] for _ in range(2)]
        
        def _helper(who, start, m):
            if start == n:
                return 0
            if dp[who][start][m] != -1:
                return dp[who][start][m]
            temp = -float('inf')
            acc = 0
            for s in range(start + 1, min(n, start + 2 * m) + 1, 1):
                acc += piles[s - 1]
                temp = max(temp, acc - _helper((who + 1) % 2, s, max(m, s - start)))
            dp[who][start][m] = temp
            return temp
        
        _helper(0, 0, 1)
        total = sum(piles)
        return int((total + dp[0][0][1]) / 2)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            piles = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(piles)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for piles in dataset:
        results.append(solution.stoneGameII(piles))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')