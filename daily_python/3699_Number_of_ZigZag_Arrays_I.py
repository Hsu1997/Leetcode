import os
import sys
from typing import List

class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        mod = (int)(10 ** 9 + 7)
        m = r - l + 1
        up = [i for i in range(m)] 
        down = [m - 1 - i for i in range(m)]
        accup = [0] * m
        accdown = [0] * m
        accdown[0] = down[0]
        for i in range(1, m):
            accup[i] = (accup[i-1] + up[i]) % mod
            accdown[i] = (accdown[i-1] + down[i]) % mod
        for p in range(2, n):
            for i in range(m):
                up[i] = accdown[i-1] if i > 0 else 0
                down[i] = (accup[m - 1] - accup[i]) % mod
            accdown[0] = down[0]
            for i in range(1, m):
                accup[i] = (accup[i-1] + up[i]) % mod
                accdown[i] = (accdown[i-1] + down[i]) % mod
        return (accup[m-1] + accdown[m-1]) % mod
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            r = int(lines[1].split('=')[1].strip()[:-1])
            l = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, r, l))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, r, l in dataset:
        results.append(solution.zigZagArrays(n, r, l))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')