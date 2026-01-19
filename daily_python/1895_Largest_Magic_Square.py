import os
import sys
from typing import List

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        vertical = [[0] * n for _ in range(m)]
        horizontal = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                vertical[i][j] = grid[i][j] + (vertical[i-1][j] if i > 0 else 0)
                horizontal[i][j] = grid[i][j] + (horizontal[i][j-1] if j > 0 else 0)
        for k in range(min(m, n), 1, -1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    check = True
                    l = vertical[i + k - 1][j] - (vertical[i-1][j] if i > 0 else 0)
                    for ii in range(i, i + k):
                        if horizontal[ii][j + k - 1] - (horizontal[ii][j - 1] if j > 0 else 0) != l:
                            check = False
                            break
                    if not check:
                        continue
                    for jj in range(j, j + k):
                        if vertical[i + k - 1][jj] - (vertical[i - 1][jj] if i > 0 else 0) != l:
                            check = False
                            break
                    if not check:
                        continue
                    d1, d2 = 0, 0
                    for d in range(k):
                        d1 += grid[i + d][j + d]
                        d2 += grid[i + d][j + k - 1 - d]
                    if d1 != l or d2 != l:
                        check = False
                    if check:
                        return k
        return 1

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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.largestMagicSquare(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
