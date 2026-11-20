import sys
import os
from typing import List

class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        ans = 0
        dp = {}
        nums.sort()
        for i in nums:
            dp[i + 1] = max(dp.get(i + 1, 0), dp.get(i, 0) + 1)
            dp[i] = max(dp.get(i, 0), dp.get(i - 1, 0) + 1)
            ans = max(ans, dp[i + 1], dp[i])
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
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    results = []
    solution = Solution()
    dataset = readDataSet(filename)
    for nums in dataset:
        results.append(solution.maxSelectedElements(nums))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')