import os
import sys
from typing import List

class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        ans = []
        n = len(grid)
        visited = [0] * (n * n + 1)
        for row in range(n):
            for col in range(n):
                val = grid[row][col]
                visited[val] += 1
                if visited[val] == 2:
                    ans.append(val)
        for i in range(1, n * n + 1):
            if visited[i] == 0:
                ans.append(i)
        return ans
    
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
        results.append(solution.findMissingAndRepeatedValues(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
