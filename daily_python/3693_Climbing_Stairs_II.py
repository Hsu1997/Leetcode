import os
import sys
from typing import List

class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        a, b, c = 0, 0, 0
        for i in range(n):
            curr = costs[i] + min(a + 9, b + 4, c + 1)
            a, b, c = b, c, curr
        return c
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            costs = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((n, costs))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, costs in dataset:
        results.append(solution.climbStairs(n, costs))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')