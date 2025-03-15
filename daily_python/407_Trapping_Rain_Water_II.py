import os
import sys
from typing import List
import heapq

class Solution:
    def in_range(self, i, j):
        return 0 <= i < self.m and 0 <= j < self.n
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        self.m = len(heightMap)
        self.n = len(heightMap[0])
        visited = [[False] * self.n for _ in range(self.m)]
        pq = []
        water = 0
        for r in range(self.m):
            heapq.heappush(pq, (heightMap[r][0], r, 0))
            heapq.heappush(pq, (heightMap[r][self.n-1], r, self.n-1))
            visited[r][0] = visited[r][self.n-1] = True
        for c in range(1, self.n - 1):
            heapq.heappush(pq, (heightMap[0][c], 0, c))
            heapq.heappush(pq, (heightMap[self.m-1][c], self.m-1, c))
            visited[0][c] = visited[self.m-1][c] = True
        while pq:
            height, i, j = heapq.heappop(pq)
            for dx, dy in {(0,1),(1,0),(0,-1),(-1,0)}:
                r = i + dx
                c = j + dy
                if self.in_range(r, c) and not visited[r][c]:
                    neighbor_height = heightMap[r][c]
                    if neighbor_height < height:
                        water += height - neighbor_height
                    visited[r][c] = True
                    heapq.heappush(pq, (max(height, neighbor_height), r, c))
        return water
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            heightMap = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(heightMap)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for heightMap in dataset:
        results.append(solution.trapRainWater(heightMap))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')