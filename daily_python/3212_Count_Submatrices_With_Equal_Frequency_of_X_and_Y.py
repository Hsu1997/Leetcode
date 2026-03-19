import os
import sys
from typing import List

class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        valid = [False] * n
        prev = [0] * n
        ans = 0
        for i in range(m):
            acc = 0
            v = False
            for j in range(n):
                if grid[i][j] == 'X':
                    valid[j] = True
                    prev[j] += 1
                elif grid[i][j] == 'Y':
                    prev[j] -= 1
                v |= valid[j]
                acc += prev[j]
                if v and (acc == 0):
                    ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(row.split("','")) for row in lines[0].split('=')[1].strip()[3:-4].split("'},{'")]
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
        results.append(solution.numberOfSubmatrices(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
