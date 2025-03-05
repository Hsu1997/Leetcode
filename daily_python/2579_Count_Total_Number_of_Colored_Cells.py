import os
import sys
from typing import List

class Solution:
    def coloredCells(self, n: int) -> int:
        return 2 * n * n - 2 * n + 1

def readDatSet(filename):
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
    dataset = readDatSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.coloredCells(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')