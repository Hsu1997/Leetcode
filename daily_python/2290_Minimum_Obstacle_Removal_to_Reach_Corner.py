import os
import sys
import heapq
from typing import List

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[m * n+1] * n for _ in range(m)]
        dp[0][0] = 1 if grid[0][0] == 1 else 0
        pq = []
        heapq.heappush(pq, (dp[0][0], 0, 0))
        dir = [(0, 1),(1, 0),(0,-1),(-1,0)]
        def in_range(i, j):
            return 0 <= i < m and 0 <= j < n
        while pq:
            remove, i, j = heapq.heappop(pq)
            if i == m-1 and j == n-1:
                return remove
            for dx, dy in dir:
                ni = i + dx
                nj = j + dy
                if not in_range(ni, nj):
                    continue
                if remove + (grid[ni][nj] == 1) < dp[ni][nj]:
                    dp[ni][nj] = min(dp[ni][nj], remove + (grid[ni][nj] == 1))
                    heapq.heappush(pq, (dp[ni][nj], ni, nj))
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
        results.append(solution.minimumObstacles(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')