import os
import sys
from typing import List
import heapq

class Solution:
    def inrange(self, i: int, j: int) -> bool:
        return 0 <= i < self.m and 0 <= j < self.n
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        self.m = len(grid)
        self.n = len(grid[0])
        query = []
        for q in queries:
            query.append(q)
        heapq.heapify(query)
        visited = [[False] * self.n for _ in range(self.m)]
        pq = [(grid[0][0], 0, 0)]
        visited[0][0] = True
        count = 0
        ansMap = {}
        while query:
            curr = heapq.heappop(query)
            while pq and pq[0][0] < curr:
                val, i, j = heapq.heappop(pq)
                count += 1
                for dx, dy in ((0,1),(1,0),(0,-1),(-1,0)):
                    x = i + dx
                    y = j + dy
                    if not self.inrange(x, y) or visited[x][y]:
                        continue
                    visited[x][y] = True
                    heapq.heappush(pq, (grid[x][y], x, y))
            ansMap[curr] = count
        ans = []
        for q in queries:
            ans.append(ansMap[q])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            queries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((grid, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, queries in dataset:
        results.append(solution.maxPoints(grid, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')