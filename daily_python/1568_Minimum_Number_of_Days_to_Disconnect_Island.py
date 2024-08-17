import os
import sys
from typing import List
import queue

class Solution:
    def in_field(self, x: int, y: int)-> bool:
        return 0 <= x < self.row and 0 <= y < self.col
    def connected(self)-> bool:
        d = [0, 1, 0, -1, 0]
        que = queue.Queue()
        visited = [[False for _ in range(self.col)] for _ in range(self.row)]
        found = False
        for i in range(self.row):
            for j in range(self.col):
                if not found and self.grid[i][j] == 1:
                    found = True
                    visited[i][j] = True
                    que.put((i,j))
                    break
            if found:
                break
        while not que.empty():
            temp = que.get()
            for k in range(4):
                x = temp[0] + d[k]
                y = temp[1] + d[k+1]
                if self.in_field(x, y) and self.grid[x][y] == 1 and not visited[x][y]:
                    visited[x][y] = True
                    que.put((x, y))
        for i in range(self.row):
            for j in range(self.col):
                if self.grid[i][j] == 1 and not visited[i][j]:
                    return False
        return True
    def minDays(self, grid: List[List[int]]) -> int:
        self.row = len(grid)
        self.col = len(grid[0])
        self.grid = grid
        count = sum(sum(r) for r in grid)
        if count < 2:
            return count
        if not self.connected():
            return 0
        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if not self.connected():
                        return 1
                    grid[i][j] = 1
        return 2
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = eval(lines[0].split('=')[1][1:-1].replace('{','[').replace('}',']'))
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
        results.append(solution.minDays(grid))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')