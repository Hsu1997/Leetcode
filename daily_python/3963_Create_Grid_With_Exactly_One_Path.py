import os
import sys
from typing import List

class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return ['.' + '#' * (n - 1)] * (m - 1) + ['.' * n]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((m, n))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n in dataset:
        results.append(solution.createGrid(m, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')