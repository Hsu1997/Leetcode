import os
import sys
from typing import List

class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        idx = 0
        for i in range(n-1):
            if nums[i] == 0:
                continue
            if nums[i] == nums[i+1]:
                ans[idx] = 2 * nums[i]
                nums[i+1] = 0
            else:
                ans[idx] = nums[i]
            idx += 1
        ans[idx] = nums[n-1]
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
        results.append(solution.applyOperations(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')