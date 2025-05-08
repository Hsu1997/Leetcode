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
        pq = [(0, 0, 0)]
        heapq.heapify(pq)
        ans = [[-1] * self.n for _ in range(self.m)]
        ans[0][0] = 0
        while pq:
            dis, x, y = heapq.heappop(pq)
            for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
                nx = x + dx
                ny = y + dy
                if not self.in_range(nx, ny) or ans[nx][ny] != -1:
                    continue
                ans[nx][ny] = max(moveTime[nx][ny], dis) +  1
                heapq.heappush(pq, (ans[nx][ny], nx, ny))
        return ans[self.m-1][self.n-1]

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