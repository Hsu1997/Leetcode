import os
import sys
from typing import List
from collections import Counter

class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        if min(complexity[1:]) <= complexity[0]:
            return 0
        ans = 1
        mod = int(1e9 + 7)
        for i in range(2, len(complexity)):
            ans = ans * i % mod
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            complexity = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(complexity)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for complexity in dataset:
        results.append(solution.countPermutations(complexity))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')