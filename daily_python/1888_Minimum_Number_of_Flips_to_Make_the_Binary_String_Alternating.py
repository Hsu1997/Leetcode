import os
import sys
from typing import List

class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        dp = [[0] * 2 for _ in range(n)]
        def check(c, x) -> int:
            return 1 if ord(c) - ord('0') == x else 0
        dp[0][0] = check(s[0], 1)
        dp[0][1] = check(s[0], 0)
        for i in range(1, n):
            dp[i][0] = dp[i-1][1] + check(s[i], 1)
            dp[i][1] = dp[i-1][0] + check(s[i], 0)
        ans = min(dp[n-1][0], dp[n-1][1])
        if n % 2 == 0:
            return ans
        zero, one = 0, 0
        for i in range(n-1, 0, -1):
            t = zero + check(s[i], 0)
            zero = one + check(s[i], 1)
            one = t
            ans = min(ans, zero + dp[i-1][0], one + dp[i-1][1])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.minFlips(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')