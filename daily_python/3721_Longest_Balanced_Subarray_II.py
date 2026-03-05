import os
import sys
from typing import List
from collections import defaultdict, deque

class SegmentTree:
    def __init__(self, prefix: List[int]):
        self.n = len(prefix)
        self.minv = [0] * (4 * self.n + 1)
        self.maxv = [0] * (4 * self.n + 1)
        self.lazy = [0] * (4 * self.n + 1)
        self._build(prefix, 1, self.n, 1)
    def _build(self, prefix: List[int], l: int, r: int, nodeidx: int):
        if l == r:
            val = prefix[l - 1]
            self.minv[nodeidx] = val
            self.maxv[nodeidx] = val
            return
        mid = (l + r) // 2
        self._build(prefix, l, mid, nodeidx * 2)
        self._build(prefix, mid + 1, r, nodeidx * 2 + 1)
        self._pushup(nodeidx)

    def _pushup(self, nodeidx: int):
        self.minv[nodeidx] = min(self.minv[nodeidx * 2], self.minv[nodeidx * 2 + 1])
        self.maxv[nodeidx] = max(self.maxv[nodeidx * 2], self.maxv[nodeidx * 2 + 1])

    def _pushdown(self, nodeidx: int):
        if self.lazy[nodeidx] != 0:
            v = self.lazy[nodeidx]
            self._applyTag(v, nodeidx * 2)
            self._applyTag(v, nodeidx * 2 + 1)
            self.lazy[nodeidx] = 0
    
    def _applyTag(self, t, nodeidx):
        self.minv[nodeidx] += t
        self.maxv[nodeidx] += t
        self.lazy[nodeidx] += t
    
    def _periodUpdate(self, start: int, end: int, t: int, l: int, r: int, nodeidx: int):
        if start <= l and end >= r:
            self._applyTag(t, nodeidx)
            return
        self._pushdown(nodeidx)
        mid = (l + r) // 2
        if start <= mid:
            self._periodUpdate(start, end, t, l, mid, nodeidx * 2)
        if end >= mid + 1:
            self._periodUpdate(start, end, t, mid + 1, r, nodeidx * 2 + 1)
        self._pushup(nodeidx)
    
    def _find(self, start: int, end: int, val: int, l: int, r: int, nodeidx: int) -> int:
        if self.minv[nodeidx] > val or self.maxv[nodeidx] < val:
            return -1
        if l == r:
            return l
        self._pushdown(nodeidx)
        mid = (l + r) // 2
        if end >= mid + 1:
            res = self._find(start, end, val, mid + 1, r, nodeidx * 2 + 1)
            if res != -1:
                return res
        if start <= mid and end >= l:
            return self._find(start, end, val, l, mid, nodeidx * 2)
        return -1
    
    def periodAdd(self, start: int, end: int, t: int):
        self._periodUpdate(start, end, t, 1, self.n, 1)

    def findZero(self, start: int) -> int:
        return self._find(start, self.n, 0, 1, self.n, 1)

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        def sgn(x : int) -> int:
            return 1 if x % 2 == 0 else -1
        prefix = [0] * n
        prefix[0] = sgn(nums[0])
        occ = defaultdict(deque)
        occ[nums[0]].append(1)
        for i in range(1, n):
            prefix[i] = prefix[i - 1]
            if not occ[nums[i]]:
                prefix[i] += sgn(nums[i])
            occ[nums[i]].append(i + 1)

        seg = SegmentTree(prefix)        
        ans = 0
        for i in range(n):
            ans = max(ans, seg.findZero(i + 1 + ans) - i)
            occ[nums[i]].popleft()
            next_pos = seg.n + 1 if not occ[nums[i]] else occ[nums[i]][0]
            seg.periodAdd(i + 1, next_pos - 1, -sgn(nums[i]))
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
        results.append(solution.longestBalanced(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')