import os
import sys
from typing import List

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        min_acc = 0
        max_acc = 0
        ans = 0
        for num in nums:
            max_acc += num
            min_acc += num
            max_acc = max(max_acc, 0)
            min_acc = min(min_acc, 0)
            ans = max(ans, max_acc, abs(min_acc))
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
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.maxAbsoluteSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')