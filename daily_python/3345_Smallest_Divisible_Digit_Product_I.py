import os
import sys
from typing import List

class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def check(num: int) -> bool:
            res = 1
            while num > 0:
                res *= (num % 10)
                num //= 10
            return res % t == 0
        while True:
            if check(n):
                return n
            n += 1
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            t = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, t))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, t in dataset:
        results.append(solution.smallestNumber(n, t))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')