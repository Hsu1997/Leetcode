import os
import sys
from typing import List

class BIT:
    def __init__(self, n: int):
        self.size = n
        self.tree1 = [0] * (n + 2)
        self.tree2 = [0] * (n + 2)
    def _lowbit(self, idx: int) -> int:
        return idx & (-idx)
    def add(self, l: int, r: int, v: int) -> None:
        self._add(l, v)
        self._add(r + 1, -v)
    def query(self, l: int, r: int) -> int:
        return self._query(r) - self._query(l - 1)
    
    def _add(self, idx: int, v: int) -> None:
        idx += 1
        d = (idx - 1) * v
        while idx <= self.size:
            self.tree1[idx] += v
            self.tree2[idx] += d
            idx += self._lowbit(idx)
    def _query(self, idx: int) -> int:
        idx += 1
        if idx > self.size:
            idx = self.size
        d = idx
        res = 0
        while idx > 0:
            res += d * self.tree1[idx] - self.tree2[idx]
            idx -= self._lowbit(idx)
        return res

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        bit = BIT(n)
        mod = 10 ** 9 + 7
        last_seen = {}
        curr = 0
        ans = 0
        for i in range(n):
            v = nums[i]
            j = (-1 if v not in last_seen else last_seen[v]) + 1
            q = bit.query(j, i)
            curr = (curr + 2 * q + (i - j + 1)) % mod
            ans = (ans + curr) % mod
            bit.add(j, i, 1)
            last_seen[v] = i
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.sumCounts(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')