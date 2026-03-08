import os
import sys
from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        if nums[1] <= nums[0]:
            return False
        n = len(nums)
        t = 0
        for i in range(1, n - 1):
            prev = nums[i] - nums[i-1]
            next = nums[i+1] - nums[i]
            if prev * next == 0:
                return False
            elif prev * next < 0:
                t += 1
            else:
                continue
        return t == 2

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
        results.append(solution.isTrionic(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')