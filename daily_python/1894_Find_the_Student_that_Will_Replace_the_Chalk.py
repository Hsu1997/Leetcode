import os
import sys
from typing import List

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total = sum(chalk)
        k %= total
        for index, curr in enumerate(chalk):
            k -= curr
            if k < 0:
                return index
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            chalk = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1][1:-1])
            dataset.append((chalk, k))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for chalk, k in dataset:
        results.append(solution.chalkReplacer(chalk, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
