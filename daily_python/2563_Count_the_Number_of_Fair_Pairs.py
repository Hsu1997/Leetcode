import os
import sys
from typing import List

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        start = n - 1
        end = n - 1
        ans = 0
        for i in range(n - 1):
            if nums[i] + nums[start] < lower:
                continue
            while start - 1 >= 0 and nums[i] + nums[start - 1] >= lower:
                start -= 1
            while end - 1 >= 0 and nums[i] + nums[end] > upper:
                end -= 1
            if i >= end:
                return ans
            start = max(start, i + 1)
            ans += end - start + 1
        return ans
    
def readDatSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            lower = int(lines[1].split('=')[1].strip()[:-1])
            upper = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, lower, upper))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDatSet(filename)
    results = []
    solution = Solution()
    for nums, lower, upper in dataset:
        results.append(solution.countFairPairs(nums, lower, upper))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')