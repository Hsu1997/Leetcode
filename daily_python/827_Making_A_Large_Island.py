import os
import sys
from typing import List

class DisjointSet:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.island_size = [1] * n
    def find(self, node):
        if self.parents[node] == node:
            return node
        self.parents[node] = self.find(self.parents[node])
        return self.parents[node]
    def union_nodes(self, i, j):
        rootA = self.find(i)
        rootB = self.find(j)
        if rootA == rootB:
            return
        if self.island_size[rootA] < self.island_size[rootB]:
            self.parents[rootA] = rootB
            self.island_size[rootB] += self.island_size[rootA]
        else:
            self.parents[rootB] = rootA
            self.island_size[rootA] += self.island_size[rootB]

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        def in_range(i, j):
            return 0 <= i < m and 0 <= j < n
        d = [(0,1),(1,0),(0,-1),(-1,0)]
        ds = DisjointSet(m * n)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for dx, dy in d:
                        x = i + dx
                        y = j + dy
                        if not in_range(x, y) or grid[x][y] == 0:
                            continue
                        ds.union_nodes(i * n + j, x * n + y)
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    neighbors = set()
                    for dx, dy in d:
                        x = i + dx
                        y = j + dy
                        if not in_range(x, y) or grid[x][y] == 0:
                            continue
                        neighbors.add(ds.find(x * n + y))
                    curr = 1
                    for neighbor in neighbors:
                        curr += ds.island_size[neighbor]
                    ans = max(ans, curr)
        if ans == 0:
            return m * n
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
        results.append(solution.largestIsland(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')