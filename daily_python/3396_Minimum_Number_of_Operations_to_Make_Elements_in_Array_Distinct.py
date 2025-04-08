import os
import sys
from typing import List
from math import ceil

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        M = max(nums)
        visited = [False] * (M + 1)
        index = -1
        for i in range(len(nums) - 1 , -1, -1):
            if visited[nums[i]]:
                index = i
                break
            visited[nums[i]] = True
        index += 1
        return ceil(index / 3)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minimumOperations(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')