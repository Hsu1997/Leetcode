import sys
import os
from typing import List

class Solution:
    def IsMagicSquares(self, grid: List[List[int]], x: int, y: int) -> bool:
        contain = [False] * 10
        for i in range(x, x+3):
            for j in range(y, y+3):
                num = grid[i][j]
                if num < 1 or num > 9 or contain[num]:
                    return False
                contain[num] = True
        for i in range(1,10):
            if contain[i] == False:
                return False
        if grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2] != 15 or grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2] != 15:
            return False
        for i in range(x, x+3):
            temp = 0
            for j in range(y, y+3):
                temp += grid[i][j]
            if temp != 15:
                return False
        for j in range(y, y+3):
            temp = 0
            for i in range(x, x+3):
                temp += grid[i][j]
            if temp != 15:
                return False
        return True

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        if m < 3 or n < 3:
            return 0
        ans = 0
        for i in range(m-2):
            for j in range(n-2):
                if self.IsMagicSquares(grid, i, j):
                    ans += 1
        return ans
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            data = block.split('=')[1].strip().strip(';').replace('{', '[').replace('}',']')
            dataset.append(eval(data))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.numMagicSquaresInside(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')