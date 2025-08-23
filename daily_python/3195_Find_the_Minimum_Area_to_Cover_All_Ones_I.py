import os
import sys
from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        left, right, top, down = n, 0, m, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    left = min(left, j)
                    right = max(right, j)
                    top = min(top, i)
                    down = max(down, i)
        return (right - left + 1) * (down - top + 1)

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
        results.append(solution.minimumArea(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')