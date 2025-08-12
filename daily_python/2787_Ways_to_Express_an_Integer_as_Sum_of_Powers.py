import os
import sys
from typing import List

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = int(1e9 + 7)
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            curr = i ** x
            if curr > n:
                return dp[n]
            for j in range(n, curr - 1, -1):
                dp[j] = (dp[j] + dp[j - curr]) % mod
        return dp[n]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            x = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, x))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, x in dataset:
        results.append(solution.numberOfWays(n, x))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')