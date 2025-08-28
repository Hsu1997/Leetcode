import os
import sys
from typing import List
from functools import lru_cache

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        def in_range(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n
        
        def alt(v: int) -> int:
            return 0 if v == 2 else 2
        
        dir = [(-1, 1), (1, 1), (1, -1), (-1, -1)]

        @lru_cache(None)
        def go_straight(i: int, j: int, d: int) -> int:
            v = grid[i][j]
            nx = i + dir[d][0]
            ny = j + dir[d][1]
            if in_range(nx, ny) and grid[nx][ny] == alt(v):
                return 1 + go_straight(nx, ny, d)
            else:
                return 1

        @lru_cache(None)
        def can_turn(i: int, j: int, d: int) -> int:
            v = grid[i][j]
            s = 1
            nx = i + dir[d][0]
            ny = j + dir[d][1]
            if in_range(nx, ny) and grid[nx][ny] == alt(v):
                s += can_turn(nx, ny, d)
            t = 1
            nd = (d + 1) % 4
            dx = i + dir[nd][0]
            dy = j + dir[nd][1]
            if in_range(dx, dy) and grid[dx][dy] == alt(v):
                t += go_straight(dx, dy, nd)
            return max(s, t)

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 1:
                    continue
                ans = max(ans, 1)
                for d in range(4):
                    nx = i + dir[d][0]
                    ny = j + dir[d][1]
                    if in_range(nx, ny) and grid[nx][ny] == 2:
                        ans = max(ans, 1 + can_turn(nx, ny, d))
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
        results.append(solution.lenOfVDiagonal(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')