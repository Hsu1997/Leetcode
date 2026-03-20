import os
import sys
from typing import List

class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                res = []
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        res.append(grid[x][y])
                res.sort()
                kmin = float('inf')
                for ptr in range(1, len(res)):
                    if res[ptr-1] != res[ptr]:
                        kmin = min(kmin, abs(res[ptr] - res[ptr-1]))
                if kmin != float('inf'):
                    ans[i][j] = kmin
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
        results.append(solution.minAbsDiff(grid, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')