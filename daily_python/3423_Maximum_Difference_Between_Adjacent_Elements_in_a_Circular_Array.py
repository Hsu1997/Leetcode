import os
import sys
from typing import List

class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans = abs(nums[0] - nums[n-1])
        for i in range(n-1):
            ans = max(ans, abs(nums[i+1] - nums[i]))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
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
        results.append(solution.maxAdjacentDistance(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')