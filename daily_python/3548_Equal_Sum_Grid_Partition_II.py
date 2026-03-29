import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def rotationRight(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        g = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                g[j][m - 1 - i] = grid[i][j]
        return g
    
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = sum(sum(row) for row in grid)
        for k in range(4):
            grid = self.rotationRight(grid)
            m, n = len(grid), len(grid[0])
            exist = set()
            exist.add(0)
            currSum = 0
            if m == 1:
                continue
            if n == 1:
                for i in range(m-1):
                    currSum += grid[i][0]
                    d = currSum * 2 - total
                    if d == 0 or d == grid[0][0] or d == grid[i][0]:
                        return True
                continue
            for i in range(m - 1):
                for j in range(n):
                    currSum += grid[i][j]
                    exist.add(grid[i][j])
                d = currSum * 2 - total
                if i == 0:
                    if d == 0 or d == grid[0][0] or d == grid[0][n-1]:
                        return True
                else:
                    if d in exist:
                        return True
        return False

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
        results.append(solution.canPartitionGrid(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')