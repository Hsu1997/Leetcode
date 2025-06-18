import os
import sys
from typing import List

class Solution:
    def __init__(self):
        self.M = 100001
        self.mod = int(1e9 + 7)
        self.fact = [0] * self.M
        self.inv_fact = [0] * self.M
    def qpow(self, x, n):
        res = 1
        while n:
            if n & 1:
                res = res * x % self.mod
            x = x * x % self.mod
            n //= 2
        return res
    def init_fact(self):
        self.fact[0] = 1
        for i in range(1, self.M):
            self.fact[i] = self.fact[i-1] * i % self.mod
        self.inv_fact[self.M - 1] = self.qpow(self.fact[self.M - 1], self.mod - 2)
        for i in range(self.M - 2, -1, -1):
            self.inv_fact[i] = self.inv_fact[i + 1] * (i + 1) % self.mod
        return
    def cnk(self, n, k):
        return (self.fact[n] * self.inv_fact[n - k] % self.mod) * self.inv_fact[k] % self.mod
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        self.init_fact()
        return (m * self.cnk(n-1, k) % self.mod) * self.qpow(m - 1, n - 1 - k) % self.mod

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            m = int(lines[1].split('=')[1].strip()[:-1])
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, m, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, m, k in dataset:
        results.append(solution.countGoodArrays(n, m, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')