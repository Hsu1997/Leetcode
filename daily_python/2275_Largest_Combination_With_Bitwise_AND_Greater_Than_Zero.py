import os
import sys
from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        count = [0] * 32
        for n in candidates:
            pos = 0
            while n:
                if n % 2:
                    count[pos] += 1
                pos += 1
                n //= 2
        return max(count)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            candidates = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(candidates)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for candidates in dataset:
        results.append(solution.largestCombination(candidates))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')