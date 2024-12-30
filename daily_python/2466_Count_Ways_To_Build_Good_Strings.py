import os
import sys
from typing import List

class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod = 10**9 + 7
        dp = [1] + [0] * high
        for length in range(1, high+1):
            if length >= zero:
                dp[length] += dp[length - zero]
            if length >= one:
                dp[length] += dp[length - one]
            dp[length] %= mod
        return sum(dp[low:high+1]) % mod
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            low = int(lines[0].split('=')[1].strip()[:-1])
            high = int(lines[1].split('=')[1].strip()[:-1])
            zero = int(lines[2].split('=')[1].strip()[:-1])
            one = int(lines[3].split('=')[1].strip()[:-1])
            dataset.append((low, high, zero, one))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for low, high, zero, one in dataset:
        results.append(solution.countGoodStrings(low, high, zero, one))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')