import os
import sys
from typing import List
import heapq

class Solution:
    def in_range(self, i: int, j: int) -> bool:
        return 0 <= i < self.m and 0 <= j < self.n
    
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        self.m = len(moveTime)
        self.n = len(moveTime[0])
        time = [[[int(1e10)] * self.n for _ in range(self.m)] for _ in range(2)]
        pq = [(0,0,0,0)]
        heapq.heapify(pq)
        while pq:
            t, x, y, step = heapq.heappop(pq)
            if time[step][x][y] < t:
                continue
            time[step][x][y] = t
            for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
                nx = x + dx
                ny = y + dy
                if not self.in_range(nx, ny) or t >= time[step ^ 1][nx][ny]:
                    continue
                arrived_time = max(t, moveTime[nx][ny]) + step + 1
                if arrived_time < time[step ^ 1][nx][ny]:
                    time[step ^ 1][nx][ny] = arrived_time
                    heapq.heappush(pq, (arrived_time, nx, ny, step ^ 1))
        return min(time[0][self.m - 1][self.n - 1], time[1][self.m - 1][self.n - 1])

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            moveTime = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(moveTime)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for moveTime in dataset:
        results.append(solution.minTimeToReach(moveTime))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')