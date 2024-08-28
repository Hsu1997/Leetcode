import os
import sys
from typing import List
import queue
from collections import deque

class Solution:
    def inrange(self, i, j):
        return 0 <= i < self.m and 0 <= j < self.n
    
    def bfs(self, grid1, grid2, i, j):
        subland = True
        que = deque()
        que.append((i, j))
        self.visited[i][j] = True
        dir = ((0,1),(1,0),(0,-1),(-1,0))
        while que:
            x, y = que.popleft()
            if grid1[x][y] == 0:
                subland = False
            for d in dir:
                nx = x + d[0]
                ny = y + d[1]
                if self.inrange(nx, ny) and not self.visited[nx][ny] and grid2[nx][ny]:
                    que.append((nx, ny))
                    self.visited[nx][ny] = True
        return subland
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.m = len(grid1)
        self.n = len(grid1[0])
        self.visited = [[False] * self.n for _ in range(self.m)]
        ans = 0
        for i in range(self.m):
            for j in range(self.n):
                if grid2[i][j] == 1 and not self.visited[i][j]:
                    ans += self.bfs(grid1, grid2, i, j)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            g1 = lines[0].split('=')[1].strip()[2:-3].split('},{')
            g2 = lines[1].split('=')[1].strip()[2:-3].split('},{')
            grid1 = [list(map(int,row.split(','))) for row in g1]
            grid2 = [list(map(int,row.split(','))) for row in g2]
            dataset.append((grid1, grid2))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid1, grid2 in dataset:
        results.append(solution.countSubIslands(grid1, grid2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')