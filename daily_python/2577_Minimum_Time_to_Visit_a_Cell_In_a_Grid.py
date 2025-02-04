import os
import sys
import heapq
from typing import List

class Solution:
    def in_range(self, i, j):
        return i >= 0 and i < self.m and j >= 0 and j < self.n
    
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        self.m = len(grid)
        self.n = len(grid[0])
        visited = [[False] * self.n for _ in range(self.m)]
        dir = [0, 1, 0, -1, 0]
        pq = [(0, 0, 0)]
        while pq:
            steps, i, j = heapq.heappop(pq)
            if i == self.m - 1 and j == self.n - 1:
                return steps
            if visited[i][j]:
                continue
            visited[i][j] = True
            for d in range(4):
                new_i = i + dir[d]
                new_j = j + dir[d+1]
                if not self.in_range(new_i, new_j):
                    continue
                wait = 1 if (grid[new_i][new_j] - steps) % 2 == 0 else 0
                next_time = max(steps + 1, grid[new_i][new_j] + wait)
                heapq.heappush(pq, (next_time, new_i, new_j))
        return -1
    
def readDatSet(filename):
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
    dataset = readDatSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.minimumTime(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')