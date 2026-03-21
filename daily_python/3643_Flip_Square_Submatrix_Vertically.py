import os
import sys
from typing import List

class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for j in range(y, y + k):
            r, vr = x, x + k - 1
            while r < vr:
                grid[r][j], grid[vr][j] = grid[vr][j], grid[r][j]
                r += 1
                vr -= 1
        return grid

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            x = int(lines[1].split('=')[1].strip()[:-1])
            y = int(lines[2].split('=')[1].strip()[:-1])
            k = int(lines[3].split('=')[1].strip()[:-1])
            dataset.append((grid, x, y, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, x, y, k in dataset:
        results.append(solution.reverseSubmatrix(grid, x, y, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')