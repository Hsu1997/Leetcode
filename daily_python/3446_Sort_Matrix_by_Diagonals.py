import os
import sys
from typing import List

class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        for row in range(n):
            temp = [grid[row + k][k] for k in range(n - row)]
            temp = sorted(temp, reverse = True)
            for k in range(n - row):
                grid[row + k][k] = temp[k]
        for col in range(1, n):
            temp = [grid[k][col + k] for k in range(n - col)]
            temp = sorted(temp)
            for k in range(n - col):
                grid[k][col + k] = temp[k]
        return grid

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
        results.append(solution.sortMatrix(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')