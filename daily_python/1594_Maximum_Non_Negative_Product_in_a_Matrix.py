import os
import sys
from typing import List

class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        Maxp = [[0] * n for _ in range(m)]
        minp = [[0] * n for _ in range(m)]
        Maxp[0][0] = minp[0][0] = grid[0][0]
        for i in range(1, m):
            Maxp[i][0] = minp[i][0] = Maxp[i-1][0] * grid[i][0]
        for j in range(1, n):
            Maxp[0][j] = minp[0][j] = Maxp[0][j-1] * grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                if grid[i][j] >= 0:
                    Maxp[i][j] = max(Maxp[i-1][j], Maxp[i][j-1]) * grid[i][j]
                    minp[i][j] = min(minp[i-1][j], minp[i][j-1]) * grid[i][j]
                else:
                    Maxp[i][j] = min(minp[i-1][j], minp[i][j-1]) * grid[i][j]
                    minp[i][j] = max(Maxp[i-1][j], Maxp[i][j-1]) * grid[i][j]
        if Maxp[m-1][n-1] < 0:
            return -1
        return Maxp[m-1][n-1] % (10 ** 9 + 7)
    
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
        results.append(solution.maxProductPath(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')