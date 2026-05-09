import os
import sys
from typing import List

class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        stack = []
        for i in range(n):
            currVal = nums[i]
            currL = i
            currR = i
            while stack and nums[i] < stack[-1][0]:
                v, l, r = stack.pop()
                currVal = max(currVal, v)
                currL = l
            stack.append((currVal, currL, currR))
        for (v, l, r) in stack:
            for i in range(l, r + 1):
                ans[i] = v
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
        results.append(solution.maxValue(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')