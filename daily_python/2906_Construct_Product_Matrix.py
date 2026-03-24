import os
import sys
from typing import List

class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        suffix = [[0] * n for _ in range(m)]
        ans = [[0] * n for _ in range(m)]
        mod = 12345
        curr = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                suffix[i][j] = curr
                curr = (curr * grid[i][j]) % mod
        curr = 1
        for i in range(m):
            for j in range(n):
                ans[i][j] = (curr * suffix[i][j]) % mod
                curr = (curr * grid[i][j]) % mod
        return ans

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
        results.append(solution.constructProductMatrix(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')