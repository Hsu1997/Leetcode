import os
import sys
from typing import List

class Solution:
    def pow(self, base: int, power: int) -> int:
        res = 1
        while power:
            if power % 2:
                res = res * base % self.mod
            base = base * base % self.mod
            power //= 2
        return res
    def countGoodNumbers(self, n: int) -> int:
        self.mod = int(1e9 + 7)
        return self.pow(5, n // 2 + n % 2) * self.pow(4, n // 2) % self.mod

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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.countGoodNumbers(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')