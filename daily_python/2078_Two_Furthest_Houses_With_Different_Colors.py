import os
import sys
from typing import List

class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        if colors[0] != colors[-1]:
            return n - 1
        for i in range(1, n // 2 + 1):
            if colors[i] != colors[0] or colors[n - 1 - i] != colors[0]:
                return n - 1 - i
        return -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            colors = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(colors)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for colors in dataset:
        results.append(solution.maxDistance(colors))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')