import os
import sys
from typing import List

class DSU:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
    def find(self, i: int) -> int:
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def combine(self, i: int, j: int) -> None:
        x = self.find(i)
        y = self.find(j)
        self.parents[y] = x
        return
    
class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        u = DSU(m * n)
        for i in range(m):
            for j in range(n):
                if i + 1 < m and grid[i][j] == grid[i+1][j]:
                    u.combine(i * n + j, (i + 1) * n + j)
                if j + 1 < n and grid[i][j] == grid[i][j+1]:
                    if u.find(i * n + j) == u.find(i * n + j + 1):
                        return True
                    u.combine(i * n + j, i * n + j + 1)
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(row.split("','")) for row in lines[0].split('=')[1].strip()[3:-4].split("'},{'")]
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
        results.append(solution.containsCycle(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')