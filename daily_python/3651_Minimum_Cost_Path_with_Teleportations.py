import os
import sys
from typing import List

class Solution:
    def modify_walk(self) -> None:
        for i in range(self.m):
            for j in range(self.n):
                if i > 0:
                    self.dp[i][j] = min(self.dp[i][j], self.dp[i-1][j] + self.grid[i][j])
                if j > 0:
                    self.dp[i][j] = min(self.dp[i][j], self.dp[i][j-1] + self.grid[i][j])

    def modify_teleport(self) -> None:
        m = self.dp[self.order[0][0]][self.order[0][1]]
        ptr = 0
        for i in range(1, len(self.order)):
            x, y = self.order[i]
            while self.grid[x][y] != self.grid[self.order[ptr][0]][self.order[ptr][1]]:
                self.dp[self.order[ptr][0]][self.order[ptr][1]] = min(self.dp[self.order[ptr][0]][self.order[ptr][1]], m)
                ptr += 1
            m = min(m, self.dp[x][y])
        while ptr < len(self.order):
            self.dp[self.order[ptr][0]][self.order[ptr][1]] = min(self.dp[self.order[ptr][0]][self.order[ptr][1]], m)
            ptr += 1

    def minCost(self, grid: List[List[int]], k: int) -> int:
        self.grid = grid
        self.m = len(grid)
        self.n = len(grid[0])
        self.dp = [[float('inf')] * self.n for _ in range(self.m)]
        self.dp[0][0] = 0
        self.order = []
        for i in range(self.m):
            for j in range(self.n):
                self.order.append((i, j))
        self.order.sort(key = lambda p : grid[p[0]][p[1]], reverse = True)
        self.modify_walk()
        for _ in range(k):
            self.modify_teleport()
            self.modify_walk()
        return self.dp[self.m - 1][self.n - 1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((grid, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, k in dataset:
        results.append(solution.minCost(grid, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')