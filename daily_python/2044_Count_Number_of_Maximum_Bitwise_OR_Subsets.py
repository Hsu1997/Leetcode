import os
import sys
from typing import List

class Solution:
    def dfs(self, nums, i, curr, target):
        if i == len(nums):
            return
        self.dfs(nums, i+1, curr, target)
        curr = curr | nums[i]
        if (curr == target):
            self.ans += (1 << (len(nums)-1-i))
        else:
            self.dfs(nums, i+1, curr, target)

    def countMaxOrSubsets(self, nums: List[int]) -> int:
        self.ans = 0
        target = 0
        for i in nums:
            target = target | i
        self.dfs(nums, 0, 0, target)
        return self.ans
    
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
        filename = os.path.splitext(__file__)[0] +'.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.countMaxOrSubsets(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')