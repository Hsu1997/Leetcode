import os
import sys
from typing import List

class UnionFind:
    def __init__(self, n):
        self.parents = [i for i in range(n + 2)]
    def find(self, i):
        if self.parents[i] == i:
            return self.parents[i]
        else:
            self.parents[i] = self.find(self.parents[i])
            return self.parents[i]
    def combine(self, i, j):
        x = self.find(i)
        y = self.find(j)
        self.parents[y] = x
        
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        n = row * col
        land = UnionFind(n)
        l = [[0] * col for _ in range(row)]
        
        def index(x, y):
            return (x - 1) * col + (y - 1)
        
        for i in range(n - 1, -1, -1):
            r, c = cells[i][0], cells[i][1]
            curr = index(r, c)
            l[r-1][c-1] = 1
            for dx, dy in ((0, 1),(1, 0),(0, -1),(-1, 0)):
                nr = r + dx
                nc = c + dy
                if 1 <= nr <= row and 1 <= nc <= col and l[nr-1][nc-1] == 1:
                    land.combine(curr, index(nr, nc))
            if r == 1:
                land.combine(curr, n)
            if r == row:
                land.combine(curr, n + 1)
            if land.find(n) == land.find(n + 1):
                return i
        return -1

    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            row = int(lines[0].split('=')[1].strip()[:-1])
            col = int(lines[1].split('=')[1].strip()[:-1])
            cells = [list(map(int, cell.split(','))) for cell in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((row, col, cells))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for row, col, cells in dataset:
        results.append(solution.latestDayToCross(row, col, cells))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')