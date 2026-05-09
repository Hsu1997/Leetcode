import os
import sys
from typing import List

class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        layers = min(m, n) // 2
        for layer in range(layers):
            r = []
            c = []
            v = []
            for i in range(layer, m - 1 - layer):
                r.append(i)
                c.append(layer)
                v.append(grid[i][layer])
            for j in range(layer, n - 1 - layer):
                r.append(m - 1 - layer)
                c.append(j)
                v.append(grid[m - 1 - layer][j])
            for i in range(m - 1 - layer, layer, -1):
                r.append(i)
                c.append(n - 1 - layer)
                v.append(grid[i][n - 1 - layer])
            for j in range(n - 1 - layer, layer, -1):
                r.append(layer)
                c.append(j)
                v.append(grid[layer][j])
            s = len(r)
            for i in range(s):
                grid[r[i]][c[i]] = v[(s - k % s + i) % s]
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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, k in dataset:
        results.append(solution.rotateGrid(grid, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')