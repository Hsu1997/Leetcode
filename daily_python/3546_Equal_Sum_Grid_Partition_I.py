import os
import sys
from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        h = [0] * m
        v = [0] * n
        total = 0
        for i in range(m):
            for j in range(n):
                h[i] += grid[i][j]
                v[j] += grid[i][j]
                total += grid[i][j]
        acc = 0
        for i in range(m):
            acc += h[i]
            if acc == total / 2:
                return True
        acc = 0
        for j in range(n):
            acc += v[j]
            if acc == total / 2:
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