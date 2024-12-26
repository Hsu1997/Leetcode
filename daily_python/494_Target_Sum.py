import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = defaultdict(int)
        dp[nums[0]] += 1
        dp[-nums[0]] += 1
        for i in range(1, len(nums)):
            curr = nums[i]
            next_dp = defaultdict(int)
            for val, count in dp.items():
                next_dp[val+curr] += count
                next_dp[val-curr] += count
            dp = next_dp
        return dp[target]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            target = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, target in dataset:
        results.append(solution.findTargetSumWays(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')