import os
import sys
from typing import List

class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        v = []
        ans = 0
        for i in range(n):
            j = n
            while j > 0 and grid[i][j - 1] == 0:
                j -= 1
            v.append(j)
        for i in range(n):
            threshold = i + 1
            k = -1
            for j in range(i, n):
                if v[j] <= threshold:
                    k = j
                    break
            if k == -1:
                return -1
            for j in range(k, i, -1):
                v[j-1], v[j] = v[j], v[j-1]
                ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(grid)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.minSwaps(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')