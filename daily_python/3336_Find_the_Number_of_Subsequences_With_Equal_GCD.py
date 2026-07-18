import os
import sys
from typing import List
from math import gcd

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        dp = [[0] * 201 for _ in range(201)]
        res = [[0] * 201 for _ in range(201)]
        dp[0][0] = 1
        for i in nums:
            for l in range(201):
                for r in range(201):
                    if dp[l][r] == 0:
                        continue
                    res[gcd(l, i)][r] = (res[gcd(l, i)][r] + dp[l][r]) % mod
                    res[l][gcd(r, i)] = (res[l][gcd(r, i)] + dp[l][r]) % mod
                    res[l][r] = (res[l][r] + dp[l][r]) % mod
                    dp[l][r] = 0
            dp, res = res, dp
        ans = 0
        for i in range(1, 201):
            ans = (ans + dp[i][i]) % mod
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
        results.append(solution.subsequencePairCount(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')