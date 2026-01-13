import os
import sys
from typing import List
from collections import deque

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mod = int(10 ** 9 + 7)
        Qmin, Qmax = deque(), deque()
        dp = [0] * (n + 1)
        prefix = [0] * (n + 1)
        dp[0], prefix[0] = 1, 1
        idx = 0
        for i in range(n):
            while Qmin and nums[Qmin[-1]] >= nums[i]:
                Qmin.pop()
            while Qmax and nums[Qmax[-1]] <= nums[i]:
                Qmax.pop()
            Qmin.append(i)
            Qmax.append(i)
            while Qmin and Qmax and nums[Qmax[0]] - nums[Qmin[0]] > k:
                if Qmin[0] == idx:
                    Qmin.popleft()
                if Qmax[0] == idx:
                    Qmax.popleft()
                idx += 1
            # [idx ~ i] => prefix[i-1] - prefix[idx-1]
            dp[i+1] = (prefix[i] -  (prefix[idx-1] if idx > 0 else 0) + mod) % mod
            prefix[i+1] = (prefix[i] + dp[i+1]) % mod
        return dp[-1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            complexity = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
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
        results.append(solution.countPartitions(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')