import os
import sys
from typing import List

class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[-1] * (k + 2) for _ in range(n)] for _ in range(m)]
        if grid[0][0] == 0:
            dp[0][0][0] = 0
        else:
            dp[0][0][1] = grid[0][0]
        for i in range(m):
            for j in range(n):
                for c in range(k + 1):
                    if dp[i][j][c] == -1:
                        continue
                    if j + 1 < n:
                        val = grid[i][j+1]
                        cost = 1 if val > 0 else 0
                        dp[i][j+1][c + cost] = max(dp[i][j+1][c + cost], dp[i][j][c] + val)
                    if i + 1 < m:
                        val = grid[i+1][j]
                        cost = 1 if val > 0 else 0
                        dp[i+1][j][c + cost] = max(dp[i+1][j][c + cost], dp[i][j][c] + val)
        ans = -1
        for c in range(k + 1):
            ans = max(ans, dp[m-1][n-1][c])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((grid, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, k in dataset:
        results.append(solution.maxPathScore(grid, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')