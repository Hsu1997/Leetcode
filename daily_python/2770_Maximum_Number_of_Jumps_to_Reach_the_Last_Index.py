import os
import sys
from typing import List

class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dp = [-n] * n
        dp[0] = 0
        for j in range(1, n):
            for i in range(j):
                if abs(nums[i] - nums[j]) <= target:
                    dp[j] = max(dp[j], dp[i] + 1)
        return dp[j] if dp[j] > 0 else -1

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
        results.append(solution.maximumJumps(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    