import os
import sys
from typing import List

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        mod = int(10**9 + 7)
        n = len(nums)

        def powmod(base: int, pow: int) -> int:
            res = 1
            while pow:
                if pow & 1:
                    res = res * base % mod
                base = base * base % mod
                pow >>= 1
            return res
        
        fac = [1] * (m + 1)
        ifac = [1] * (m + 1)
        for i in range(1, m + 1):
            fac[i] = i * fac[i-1] % mod
        ifac[m] = powmod(fac[m], mod - 2)
        for i in range(m-1, -1, -1):
            ifac[i] = ifac[i + 1] * (i + 1) % mod
        
        numpow = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m + 1):
                numpow[i][j] = numpow[i][j-1] * nums[i] % mod
        
        dp = [[[[0] * (k + 1) for p in range(m + 1)] for j in range(m + 1)] for i in range(n)]
        for j in range(m + 1):
            take = j
            carry = take
            dp[0][take][carry][0] = numpow[0][take] * ifac[take] % mod
        
        for i in range(n - 1):
            for j in range(m + 1):
                for p in range(m + 1):
                    for q in range(k + 1):
                        curr = dp[i][j][p][q]
                        if curr == 0:
                            continue
                        for take in range(m + 1 - j):
                            p2 = (p >> 1) + take
                            q2 = q + (p & 1)
                            if q2 > k:
                                continue
                            add = curr * numpow[i+1][take] % mod
                            add = add * ifac[take] % mod
                            dp[i+1][j+take][p2][q2] = (dp[i+1][j+take][p2][q2] + add) % mod
        
        ans = 0
        for p in range(m + 1):
            for q in range(k + 1):
                if bin(p).count('1') + q == k:
                    ans = (ans + dp[n-1][m][p][q] * fac[m]) % mod
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            nums = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((m, k, nums))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, k, nums in dataset:
        results.append(solution.magicalSum(m, k, nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')