import os
import sys
from typing import List

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        dp = [[0] * 3 for _ in range(k+1)]
        # 0 : empty, 1 : long, 2 : short
        for j in range(k+1):
            dp[j][1] = -prices[0]
            dp[j][2] = prices[0]
        for i in range(1, n):
            for j in range(k, 0, -1):
                dp[j][2] = max(dp[j][2], dp[j][0] + prices[i])
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i])
                dp[j][0] = max(dp[j][0], dp[j-1][1] + prices[i], dp[j-1][2] - prices[i])
            dp[0][1] = max(dp[0][1], -prices[i])
            dp[0][2] = max(dp[0][2], prices[i])
        return dp[-1][0]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            prices = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((prices, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for prices, k in dataset:
        results.append(solution.maximumProfit(prices, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')