import os
import sys
from typing import List

class Solution:
    def maxProduct(self, n: int) -> int:
        v1, v2 = -1, -1 
        while n:
            curr = n % 10
            if curr > v1:
                v2 = v1
                v1 = curr
            else:
                v2 = max(v2, curr)
            n //= 10
        return v1 * v2

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
        results.append(solution.maxProduct(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')