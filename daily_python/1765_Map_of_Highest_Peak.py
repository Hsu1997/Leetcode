import os
import sys
from typing import List

class Solution:
    def in_range(self, i, j, m, n):
        return i >= 0 and i < m and j >= 0 and j < n
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m = len(isWater)
        n = len(isWater[0])
        ans = [[m * n] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    ans[i][j] = 0
        for i in range(m):
            for j in range(n):
                neighbor = m * n
                if self.in_range(i-1, j, m, n):
                    neighbor = min(neighbor, ans[i-1][j])
                if self.in_range(i, j-1, m, n):
                    neighbor = min(neighbor, ans[i][j-1])
                ans[i][j] = min(ans[i][j], neighbor + 1)
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                neighbor = m * n
                if self.in_range(i+1, j, m, n):
                    neighbor = min(neighbor, ans[i+1][j])
                if self.in_range(i, j+1, m, n):
                    neighbor = min(neighbor, ans[i][j+1])
                ans[i][j] = min(ans[i][j], neighbor + 1)      
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            isWater = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(isWater)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for isWater in dataset:
        results.append(solution.highestPeak(isWater))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
