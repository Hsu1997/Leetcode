import os
import sys
from typing import List

class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 10 ** 9 + 7
        a = 6
        b = 6
        for _ in range(n - 1):
            next_a = (a * 3 + b * 2) % mod
            next_b = (a * 2 + b * 2) % mod
            a, b = next_a, next_b
        return (a + b) % mod
    
def readDataSet(filename):
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
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.numOfWays(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')