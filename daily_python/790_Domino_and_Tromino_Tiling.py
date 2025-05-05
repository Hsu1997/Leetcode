import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def numTilings(self, n: int) -> int:
        if n < 3:
            return n
        mod = int(1e9+7)
        a = [0] * (n+1)
        b = [0] * (n+1)
        a[0], a[1], a[2] = 1, 1, 2
        b[0], b[1], b[2] = 0, 2, 4
        for i in range(3, n+1):
            a[i] = (a[i-1] + a[i-2] + b[i-2]) % mod
            b[i] = (2 * a[i-1] + b[i-1]) % mod
        return a[n]
    
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
        results.append(solution.numTilings(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')