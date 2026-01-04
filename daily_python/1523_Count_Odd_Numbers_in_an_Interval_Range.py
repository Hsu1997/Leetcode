import os
import sys
from typing import List

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low + 1) // 2 + (low % 2 and high % 2)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            low = int(lines[0].split('=')[1].strip()[:-1])
            high = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((low, high))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for low, high in dataset:
        results.append(solution.countOdds(low, high))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')