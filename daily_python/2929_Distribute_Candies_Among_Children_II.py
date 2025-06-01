import os
import sys
from typing import List

class Solution:
    def cal(self, n):
        if n < 0:
            return 0
        return n * (n - 1) / 2
    
    def distributeCandies(self, n: int, limit: int) -> int:
        return int(self.cal(n + 2) - 3 * self.cal(n - (limit + 1) + 2) + 3 * self.cal(n - 2 * (limit + 1) + 2) - self.cal(n - 3 * (limit + 1) + 2))

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            limit = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, limit))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, limit in dataset:
        results.append(solution.distributeCandies(n, limit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')