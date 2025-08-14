import os
import sys
from typing import List

class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        ans = 0
        for i in range(n):
            ans += fruits[i][i]
        dp = [0] * n
        prev = [0] * n
        prev[n-1] = fruits[0][n-1]
        for i in range(1, n-1):
            for j in range(max(i+1, n-1-i), n):
                best = prev[j]
                if j > 0:
                    best = max(best, prev[j-1])
                if j < n-1:
                    best = max(best, prev[j+1])
                dp[j] = fruits[i][j] + best
            dp, prev = prev, dp
        ans += prev[n-1]
        dp = [0] * n
        prev = [0] * n
        prev[n-1] = fruits[n-1][0]
        for j in range(1, n-1):
            for i in range(max(j+1, n-1-j), n):
                best = prev[i]
                if i > 0:
                    best = max(best, prev[i-1])
                if i < n-1:
                    best = max(best, prev[i+1])
                dp[i] = fruits[i][j] + best
            dp, prev = prev, dp
        ans += prev[n-1]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            fruits = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(fruits)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for fruits in dataset:
        results.append(solution.maxCollectedFruits(fruits))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')