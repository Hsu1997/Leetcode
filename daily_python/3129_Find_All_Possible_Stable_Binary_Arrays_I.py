import os
import sys
from typing import List

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        dp = [[[0] * 2 for _ in range(one + 1)] for _ in range(zero + 1)]
        mod = int(10**9 + 7)
        for i in range(zero + 1):
            for j in range(one + 1):
                for k in range(2):
                    if i == 0:
                        if k == 0 or j > limit:
                            dp[i][j][k] = 0
                        else:
                            dp[i][j][k] = 1
                    elif j == 0:
                        if k == 1 or i > limit:
                            dp[i][j][k] = 0
                        else:
                            dp[i][j][k] = 1
                    elif k == 0:
                        dp[i][j][k] = dp[i-1][j][0] + dp[i-1][j][1]
                        if i > limit:
                            dp[i][j][k] -= dp[i-limit-1][j][1]
                    else:
                        dp[i][j][k] = dp[i][j-1][0] + dp[i][j-1][1]
                        if j > limit:
                            dp[i][j][k] -= dp[i][j-limit-1][0]
                    dp[i][j][k] %= mod
        return (dp[zero][one][0] + dp[zero][one][1]) % mod

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            zero = int(lines[0].split('=')[1].strip()[:-1])
            one = int(lines[1].split('=')[1].strip()[:-1])
            limit = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((zero, one, limit))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for zero, one, limit in dataset:
        results.append(solution.numberOfStableArrays(zero, one, limit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')