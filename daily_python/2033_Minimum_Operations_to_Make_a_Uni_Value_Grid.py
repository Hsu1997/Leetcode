import os
import sys
from typing import List

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        remainder = grid[0][0] % x
        if any(element % x != remainder for row in grid for element in row):
            return -1
        nums = [element // x for row in grid for element in row]
        n = len(nums)
        sorted(nums)
        median = nums[n//2]
        ans = sum(abs(num - median) for num in nums)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            n = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((grid, n))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid, n in dataset:
        results.append(solution.minOperations(grid, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')