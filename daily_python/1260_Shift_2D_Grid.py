import os
import sys
from typing import List

class Solution:
    def gridSwap(self, grid: List[List[int]], start: int, end: int) -> None:
        m, n = len(grid), len(grid[0])
        while start < end:
            grid[start // n][start % n], grid[end // n][end % n] = grid[end // n][end % n], grid[start // n][start % n]
            start += 1
            end -= 1
        return
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        k %= m * n
        self.gridSwap(grid, 0, m * n - 1)
        self.gridSwap(grid, 0, k - 1)
        self.gridSwap(grid, k, m * n - 1)
        return grid
    
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
        results.append(solution.shiftGrid(grid, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
