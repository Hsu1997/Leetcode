import os
import sys
from typing import List
import heapq

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1 or max(nums) > total // 2:
            return False
        total //= 2
        dp = [[False] * (total + 1) for _ in range(2)]
        dp[0][0] = True
        dp[1][0] = True
        dp[0][nums[0]] = True
        for i in range(1, len(nums)):
            curr = nums[i]
            for j in range(1, total+1):
                dp[i % 2][j] = dp[(i-1) % 2][j]
                if j - curr >= 0 and dp[(i-1) % 2][j - curr]:
                    dp[i % 2][j] = True
            if dp[i % 2][total]:
                return True
        return False
    
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
        results.append(solution.canPartition(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')