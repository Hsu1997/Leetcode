import os
import sys
from typing import List

class Solution:
    def put(self, i: int) -> None:
        if i > self.ans[0]:
            self.ans[0], self.ans[1], self.ans[2] = i, self.ans[0], self.ans[1]
        elif i > self.ans[1] and i != self.ans[0]:
            self.ans[1], self.ans[2] = i, self.ans[1]
        elif i > self.ans[2] and i != self.ans[0] and i != self.ans[1]:
            self.ans[2] = i
        else:
            return
        
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        self.ans = [0] * 3
        acc1 = [[0] * (n + 2) for _ in range(m + 1)]
        acc2 = [[0] * (n + 2) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                acc1[i+1][j+1] = grid[i][j] + acc1[i][j]
                acc2[i+1][j+1] = grid[i][j] + acc2[i][j+2]
        for i in range(m):
            for j in range(n):
                self.put(grid[i][j])
                for l in range(1, min(m, n)):
                    left = j - l
                    right = j + l
                    top = i - l
                    down = i + l
                    if left < 0 or right >= n or top < 0 or down >= m:
                        break
                    curr = (acc2[i+1][left+1] - acc2[top][j+2]) + (acc1[i+1][right+1] - acc1[top][j]) + (acc2[down+1][j+1] - acc2[i][right+2]) + (acc1[down+1][j+1] - acc1[i][left]) - (grid[i][left] + grid[top][j] + grid[i][right] + grid[down][j])
                    self.put(curr)
        while self.ans and self.ans[-1] == 0:
            self.ans.pop()
        return self.ans

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
        results.append(solution.getBiggestThree(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')