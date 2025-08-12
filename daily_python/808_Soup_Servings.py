import os
import sys
from typing import List
from math import ceil

class Solution:
    def soupServings(self, n: int) -> float:
        m = ceil(n / 25)
        dp = {}
        dp[0] = {0 : 0.5}
        for i in range(1, m + 1):
            dp[0][i] = 1
            dp[i] = {0 : 0}
            for j in range(1, i + 1):
                dp[i][j] = (dp[max(0, i-4)][j] + dp[max(0, i-3)][j-1] + dp[max(0, i-2)][max(0, j-2)] + dp[i-1][max(0, j-3)]) / 4
                dp[j][i] = (dp[max(0, j-4)][i] + dp[max(0, j-3)][i-1] + dp[max(0, j-2)][max(0, i-2)] + dp[j-1][max(0, i-3)]) / 4
            if dp[i][i] > 1 - 1e-5:
                return 1
        return dp[m][m]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.soupServings(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')