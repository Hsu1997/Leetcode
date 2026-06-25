import os
import sys
from typing import List

class Solution:
    def mul(self, a, b):
        m = len(a)
        n = len(a[0])
        k = len(b[0])
        if n != len(b):
            return None
        res = [[0] * k for _ in range(m)]
        for i in range(m):
            for l in range(n):
                if a[i][l] == 0:
                    continue
                for j in range(k):
                    res[i][j] = (res[i][j] + a[i][l] * b[l][j]) % self.mod
        return res
    
    def pow(self, base, p, res):
        if len(base) != len(base[0]):
            return None
        # res = [[0] * len(base) for _ in range(len(base))]
        # for i in range(len(base)):
        #     res[i][i] = 1
        while p:
            if p & 1:
                res = self.mul(res, base)
            base = self.mul(base, base)
            p >>= 1
        return res
    
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        self.mod = int(10**9 + 7)
        m = r - l + 1
        base = [[0] * (m * 2)]
        for i in range(m):
            base[0][i] = i
            base[0][m + i] = m - 1 - i
        trans = [[0] * (m * 2) for _ in range(m * 2)]
        for i in range(m):
            for j in range(m, m + i):
                trans[i][j] = 1
            for j in range(i + 1, m):
                trans[m + i][j] = 1
        result = self.pow(trans, n - 2, base)
        ans = 0
        for i in range(m * 2):
            ans = (ans + result[0][i]) % self.mod
        return ans
    
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