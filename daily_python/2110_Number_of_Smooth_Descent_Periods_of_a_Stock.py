import os
import sys
from typing import List

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 1
        c = 1
        for i in range(1, n):
            if prices[i] + 1 == prices[i-1]:
                c += 1
            else:
                c = 1
            ans += c
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            prices = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(prices)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for prices in dataset:
        results.append(solution.getDescentPeriods(prices))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')