import os
import sys
from typing import List

class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        profitSum = [0] * (n + 1)
        priceSum = [0] * (n + 1)
        for i in range(n):
            profitSum[1 + i] = profitSum[i] + prices[i] * strategy[i]
            priceSum[1 + i] = priceSum[i] + prices[i]
        ans = profitSum[n]
        for i in range(n - k + 1):
            left = profitSum[i]
            mid = priceSum[i + k] - priceSum[i + k // 2]
            right = profitSum[n] - profitSum[i + k]
            ans = max(ans, left + mid + right)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            prices = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            strategy  = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((prices, strategy, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for prices, strategy, k in dataset:
        results.append(solution.maxProfit(prices, strategy, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')