import os
import sys
from typing import List
from collections import deque

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        def in_range(i, j):
            return 0 <= i < m and 0 <= j < n
        d = [(0,1),(0,-1),(1,0),(-1,0)]
        que = deque([(0,0)])
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 0
        while que:
            r, c = que.popleft()
            for dir in range(4):
                nr = r + d[dir][0]
                nc = c + d[dir][1]
                if not in_range(nr, nc):
                    continue
                cost = 0 if grid[r][c] - 1 == dir else 1
                if dist[nr][nc] <= dist[r][c] + cost:
                    continue
                dist[nr][nc] = dist[r][c] + cost
                if cost == 0:
                    que.appendleft((nr, nc))
                else:
                    que.append((nr, nc))
        return dist[m-1][n-1]
    
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
        results.append(solution.minCost(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    