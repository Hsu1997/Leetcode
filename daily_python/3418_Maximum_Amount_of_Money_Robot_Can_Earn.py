import os
import sys
from typing import List

class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[[float('-inf')] * 3 for _ in range(n)] for _ in range(m)]
        dp[0][0][0] = coins[0][0]
        if coins[0][0] < 0:
            dp[0][0][1] = 0
        for j in range(1, n):
            dp[0][j][0] = dp[0][j-1][0] + coins[0][j]
            dp[0][j][1] = dp[0][j-1][1] + coins[0][j]
            dp[0][j][2] = dp[0][j-1][2] + coins[0][j]
            if coins[0][j] < 0:
                dp[0][j][1] = max(dp[0][j][1], dp[0][j-1][0])
                dp[0][j][2] = max(dp[0][j][2], dp[0][j-1][1])
        for i in range(1, m):
            dp[i][0][0] = dp[i-1][0][0] + coins[i][0]
            dp[i][0][1] = dp[i-1][0][1] + coins[i][0]
            dp[i][0][2] = dp[i-1][0][2] + coins[i][0]
            if coins[i][0] < 0:
                dp[i][0][1] = max(dp[i][0][1], dp[i-1][0][0])
                dp[i][0][2] = max(dp[i][0][2], dp[i-1][0][1])
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j]
                dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j]
                dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j]
                if coins[i][j] < 0:
                    dp[i][j][1] = max(dp[i][j][1], max(dp[i-1][j][0], dp[i][j-1][0]))
                    dp[i][j][2] = max(dp[i][j][2], max(dp[i-1][j][1], dp[i][j-1][1]))
        return max(dp[m-1][n-1][k] for k in range(3))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            coins = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(coins)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for coins in dataset:
        results.append(solution.maximumAmount(coins))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')