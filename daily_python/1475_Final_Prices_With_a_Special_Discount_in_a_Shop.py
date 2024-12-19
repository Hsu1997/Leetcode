import os
import sys
from collections import deque
from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        stack = deque()
        for i in range(n-1, -1, -1):
            curr = prices[i]
            while stack and stack[-1] > curr:
                stack.pop()
            if stack:
                prices[i] -= stack[-1]
            stack.append(curr)
        return prices

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(arr)
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
        results.append(solution.finalPrices(prices))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')