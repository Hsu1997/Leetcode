import os
import sys
from typing import List, Optional
from collections import deque
import heapq

class Solution:    
    def inRange(self, grid: List[List[int]], i: int, j: int) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n  
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        dir = [(0,1),(1,0),(0,-1),(-1,0)]
        n = len(grid)
        safeFactor = [[-1] * n for _ in range(n)]
        que = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    safeFactor[i][j] = 0
                    que.append((i, j))
        while que:
            x, y = que.popleft()
            for d in dir:
                nx = x + d[0]
                ny = y + d[1]
                if not self.inRange(grid, nx, ny) or safeFactor[nx][ny] != -1:
                    continue
                safeFactor[nx][ny] = safeFactor[x][y] + 1
                que.append((nx, ny))
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True
        pq = [(-safeFactor[0][0], 0, 0)]
        while pq:
            sf, x, y = heapq.heappop(pq)
            sf *= -1
            if x == n - 1 and y == n -1:
                return sf
            for d in dir:
                nx = x + d[0]
                ny = y + d[1]
                if not self.inRange(grid, nx, ny) or visited[nx][ny]:
                    continue
                visited[nx][ny] = True
                heapq.heappush(pq, (-min(sf, safeFactor[nx][ny]), nx, ny))
        return -1    
    
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
        results.append(solution.maximumSafenessFactor(grid))
    for index, result in enumerate(results):
        print(f'Example {index} : {result}')