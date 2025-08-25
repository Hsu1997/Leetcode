import os
import sys
from typing import List

class Solution:
    def cover(self, u, d, l, r) -> int:
        left, right, top, down = self.n, 0, self.m, 0
        for i in range(u, d + 1):
            for j in range(l, r + 1):
                if self.grid[i][j]:
                    left = min(left, j)
                    right = max(right, j)
                    top = min(top, i)
                    down = max(down, i)
        return (right - left + 1) * (down - top + 1) if left <= right else 0
    
    def minimumSum(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.m = len(grid)
        self.n = len(grid[0])
        ans = self.m * self.n
        for i in range(self.m - 1):
            for j in range(self.n - 1):
                # [0,i,0,j] [0,i,j+1,n-1] [i+1,m-1,0,j] [i+1,m-1,j+1,n-1]
                ans = min(ans, 
                          self.cover(0,i,0,self.n-1) + self.cover(i+1,self.m-1,0,j) + self.cover(i+1,self.m-1,j+1,self.n-1), 
                          self.cover(0,self.m-1,0,j) + self.cover(0,i,j+1,self.n-1) + self.cover(i+1,self.m-1,j+1,self.n-1),
                          self.cover(0,i,0,j) + self.cover(0,i,j+1,self.n-1) + self.cover(i+1,self.m-1,0,self.n-1),
                          self.cover(0,i,0,j) + self.cover(0,self.m-1,j+1,self.n-1) + self.cover(i+1,self.m-1,0,j)
                          )
        for h1 in range(self.m - 2):
            for h2 in range(h1 + 1, self.m - 1):
                ans = min(ans, self.cover(0,h1,0,self.n-1) + self.cover(h1+1,h2,0,self.n-1) + self.cover(h2+1, self.m-1, 0, self.n-1))
        for v1 in range(self.n-2):
            for v2 in range(v1+1, self.n - 1):
                ans = min(ans, self.cover(0,self.m-1,0,v1) + self.cover(0,self.m-1,v1+1,v2) + self.cover(0,self.m-1,v2+1,self.n-1))
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
        results.append(solution.minimumSum(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')