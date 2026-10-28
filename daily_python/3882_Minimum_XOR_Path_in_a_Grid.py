import os
import sys
from typing import List

class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[False] * 1024 for _ in range(n)]
        for i in range(m):
            next = [[False] * 1024 for _ in range(n)]
            for j in range(n):
                curr = grid[i][j]
                if i == 0 and j == 0:
                    next[0][curr] = True
                    continue
                for k in range(1024):
                    if dp[j][k] or (j > 0 and next[j-1][k]):
                        next[j][curr ^ k] = True
            dp = next
        for k in range(1024):
            if dp[n-1][k]:
                return k
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(grid)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.minCost(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')