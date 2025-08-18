import os
import sys
from typing import List

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0:
            return 1
        dp = [0] * (n + 1)
        dp[0] = 1
        ans = 0
        acc = 1
        for i in range(1, n + 1):
            if 0 <= i - maxPts - 1 < k:
                acc -= dp[i - maxPts - 1]
            dp[i] = acc / maxPts
            if i < k:
                acc += dp[i]
            else:
                ans += dp[i]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            maxPts = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, k, maxPts))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k, maxPts in dataset:
        results.append(solution.new21Game(n, k, maxPts))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')