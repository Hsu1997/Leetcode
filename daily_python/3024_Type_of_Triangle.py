import sys
import os
from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums = sorted(nums)
        if nums[0] + nums[1] <= nums[2]:
            return "none"
        if nums[0] == nums[1] and nums[1] == nums[2]:
            return "equilateral"
        if nums[0] == nums[1] or nums[1] == nums[2]:
            return "isosceles"
        return "scalene"

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
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    results = []
    solution = Solution()
    dataset = readDataSet(filename)
    for nums in dataset:
        results.append(solution.triangleType(nums))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')