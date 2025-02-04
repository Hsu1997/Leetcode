import os
import sys
from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = nums[0]
        acc = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                acc += nums[i]
            else:
                acc = nums[i]
            ans = max(ans, acc)
        return ans

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
    solution = Solution()
    results = []
    for nums in dataset:
        results.append(solution.maxAscendingSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    