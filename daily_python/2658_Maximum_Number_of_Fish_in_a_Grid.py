import os
import sys
from typing import Optional, List
from collections import deque

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visited = [[False] * n for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] and not visited[i][j]:
                    ans = max(ans, self.dfs(grid, visited, i, j))
        return ans
    def dfs(self, grid: List[List[int]], visited: List[List[bool]], i: int, j: int)-> int:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0 or visited[i][j]:
            return 0
        visited[i][j] = True
        fish_count = grid[i][j]
        directions = [(1,0),(0,1),(-1,0),(0,-1)]
        for dx, dy in directions:
            fish_count += self.dfs(grid, visited, i + dx, j + dy)
        return fish_count

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
    solution = Solution()
    results = []
    for grid in dataset:
        results.append(solution.findMaxFish(grid))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')