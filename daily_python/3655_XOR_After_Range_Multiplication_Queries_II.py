import os
import sys
from typing import List

class Solution:
    def powmod(self, base, pow):
        mod = 10 ** 9 + 7
        res = 1
        while pow:
            if pow & 1:
                res = (res * base) % mod
            base = (base * base) % mod
            pow //= 2
        return res

    def reversemul(self, x):
        mod = 10 ** 9 + 7
        return self.powmod(x, mod - 2)
    
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        T = int(n ** 0.5)
        mod = 10 ** 9 + 7
        group = [[] for _ in range(T)]
        for l, r, k, v in queries:
            if k < T:
                group[k].append((l, r, v))
            else:
                for i in range(l, r + 1, k):
                    nums[i] = (nums[i] * v) % mod
        for k in range(1, T):
            if not group[k]:
                continue
            accmul = [1] * (n + T)
            for l, r, v in group[k]:
                right = l + (r - l) // k * k + k
                accmul[l] = (accmul[l] * v) % mod
                accmul[right] = (accmul[right] * self.reversemul(v)) % mod
            for i in range(k, n):
                accmul[i] = (accmul[i] * accmul[i - k]) % mod
            for i in range(n):
                nums[i] = (nums[i] * accmul[i]) % mod
        ans = 0
        for i in nums:
            ans ^= i
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((nums, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, queries in dataset:
        results.append(solution.xorAfterQueries(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')