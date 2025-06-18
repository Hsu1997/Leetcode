import os
import sys

mod = 10 ** 9 + 7
M = 100001
fact = [0] * M
inv_fact = [0] * M

def qpow(x, n):
    res = 1
    while n:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n //= 2
    return res

def init_fact():
    if fact[0] == 1:
        return
    fact[0] = 1
    for i in range(1, M):
        fact[i] = fact[i-1] * i % mod
    inv_fact[M - 1] = qpow(fact[M - 1], mod - 2)
    for i in range(M - 2, -1, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod
    return

def cnk(n, k):
    return (fact[n] * inv_fact[n - k] % mod) * inv_fact[k] % mod

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        init_fact()
        return (m * cnk(n-1, k) % mod) * qpow(m - 1, n - 1 - k) % mod
    
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