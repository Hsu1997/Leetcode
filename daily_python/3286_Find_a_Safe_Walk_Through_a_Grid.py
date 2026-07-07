import os
import sys
from typing import List
from collections import deque

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dir = [[0, 1],[1, 0],[0, -1],[-1, 0]]
        dp = [[m * n + 1] * n for _ in range(m)]
        q = deque()
        q.append([0, 0])
        dp[0][0] = grid[0][0]
        while dp[m-1][n-1] == m * n + 1:
            x, y = q.popleft()
            for dx, dy in dir:
                nx = x + dx
                ny = y + dy
                if (not 0 <= nx < m or not 0 <= ny < n) or (dp[nx][ny] != m * n + 1):
                    continue
                dp[nx][ny] = dp[x][y] + grid[nx][ny]
                if grid[nx][ny] == 0:
                    q.appendleft([nx, ny])
                else:
                    q.append([nx, ny])
        return health > dp[m-1][n-1]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            health = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((grid, health))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, health in dataset:
        results.append(solution.findSafeWalk(grid, health))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    