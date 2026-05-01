import os
import sys
from typing import List

class DSU:
    def __init__(self, r, c):
        self.n = r * c
        self.c = c
        self.parents = [i for i in range(self.n)]
    def find(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def combine(self, i, j):
        x = self.find(i)
        y = self.find(j)
        self.parents[y] = x

class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        graph = DSU(m, n)
        
        def id(x, y):
            return x * n + y
        def detectL(x, y):
            if y - 1 >= 0 and grid[x][y-1] in [1,4,6]:
                graph.combine(id(x,y), id(x, y-1))
        def detectR(x, y):
            if y + 1 < n and grid[x][y+1] in [1,3,5]:
                graph.combine(id(x,y), id(x,y+1))
        def detectU(x, y):
            if x - 1 >= 0 and grid[x-1][y] in [2,3,4]:
                graph.combine(id(x,y), id(x-1,y))
        def detectD(x, y):
            if x + 1 < m and grid[x+1][y] in [2,5,6]:
                graph.combine(id(x,y), id(x+1,y))
        def handler(x, y):
            if grid[x][y] == 1:
                detectL(x, y)
                detectR(x, y)
            elif grid[x][y] == 2:
                detectU(x, y)
                detectD(x, y)
            elif grid[x][y] == 3:
                detectL(x, y)
                detectD(x, y)
            elif grid[x][y] == 4:
                detectR(x, y)
                detectD(x, y)
            elif grid[x][y] == 5:
                detectL(x, y)
                detectU(x, y)
            elif grid[x][y] == 6:
                detectR(x, y)
                detectU(x, y)

        for i in range(m):
            for j in range(n):
                handler(i, j)
        
        return graph.find(0) == graph.find(m * n - 1)
    
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
        results.append(solution.hasValidPath(grid))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')