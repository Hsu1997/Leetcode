import os
import sys
from typing import List

class Solution:
    def minPartitions(self, n: str) -> int:
        return max([ord(c) - ord('0') for c in list(n)])
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.minPartitions(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')