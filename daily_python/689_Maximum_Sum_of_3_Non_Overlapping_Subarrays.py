import os
import sys
from typing import List

class Solution:
    def helper(self, start, taken, acc, k, memo):
        if taken == 3:
            return 0
        if start >= len(acc):
            return float('-INF')
        if memo[start][taken] != -1:
            return memo[start][taken]
        take = acc[start] + self.helper(start+k, taken+1, acc, k, memo)
        skip = self.helper(start+1, taken, acc, k, memo)
        memo[start][taken] = max(take, skip)
        return memo[start][taken]
    
    def findroute(self, start, taken, acc, k, memo, index):
        if taken == 3 or start >= len(acc):
            return
        take = acc[start] + self.helper(start+k, taken+1, acc, k, memo)
        skip = self.helper(start+1, taken, acc, k, memo)
        if take >= skip:
            index.append(start)
            self.findroute(start+k, taken+1, acc, k, memo, index)
        else:
            self.findroute(start+1, taken, acc, k, memo, index)
        
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        acc = []
        curr = 0
        for i in range(k):
            curr += nums[i]
        acc.append(curr)
        for i in range(k, n):
            curr = curr - nums[i-k] + nums[i]
            acc.append(curr)
        memo = [[-1] * 3 for _ in range(len(acc))]
        index = []
        self.helper(0, 0, acc, k, memo)
        self.findroute(0, 0, acc, k, memo, index)
        return index
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.maxSumOfThreeSubarrays(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')