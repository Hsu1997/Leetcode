import os
import sys
from typing import List

class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [1] * m
        for j in range(n-1):
            dp_temp = [0] * m
            update = False
            for i in range(m):
                if dp[i]:
                    if i-1 >= 0 and grid[i-1][j+1] > grid[i][j]:
                        dp_temp[i-1] = 1
                        update = True
                    if grid[i][j+1] > grid[i][j]:
                        dp_temp[i] = 1
                        update = True
                    if i+1 < m and grid[i+1][j+1] > grid[i][j]:
                        dp_temp[i+1] = 1
                        update = True
            if not update:
                return j
            dp = dp_temp
        return n-1
    
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
        results.append(solution.maxMoves(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')