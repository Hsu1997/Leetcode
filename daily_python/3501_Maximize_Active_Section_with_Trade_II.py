import os
import sys
from typing import List
from bisect import bisect_left, bisect_right

class SparseTable:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        l = 1
        while (1 << (l + 1)) <= self.n:
            l += 1
        self.t = [[0] * self.n for _ in range(l + 1)]
        self.t[0] = nums
        for i in range(1, l + 1):
            for j in range(self.n - (1 << i) + 1):
                self.t[i][j] = max(self.t[i-1][j], self.t[i-1][j + (1 << (i - 1))])
    def query(self, start: int, end: int) -> int:
        if start > end:
            return 0
        l = end - start + 1
        p = 0
        while 1 << (p + 1) <= l:
            p += 1
        return max(self.t[p][start], self.t[p][end - (1 << p) + 1])
    
class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        contiguousZero = []
        starting = []
        ending = []
        one = 0
        acc = 0
        for i in range(len(s)):
            c = s[i]
            if c == '0':
                acc += 1
            else:
                one += 1
                if acc > 0:
                    contiguousZero.append(acc)
                    starting.append(i - acc)
                    ending.append(i - 1)
                    acc = 0
        if acc > 0:
            contiguousZero.append(acc)
            starting.append(len(s) - acc)
            ending.append(len(s) - 1)
        m = len(contiguousZero)
        if m < 2:
            return [one] * len(queries)
        twoZeroPeriods = []
        for i in range(len(contiguousZero) - 1):
            twoZeroPeriods.append(contiguousZero[i] + contiguousZero[i + 1])
        st = SparseTable(twoZeroPeriods)
        ans = []
        for start, end in queries:
            l1 = bisect_left(ending, start)
            l2 = bisect_right(starting, end) - 1
            if l1 > m - 1 or l2 < 0 or l1 >= l2:
                ans.append(one)
                continue
            firstLen = ending[l1] - max(start, starting[l1]) + 1
            lastLen = min(end, ending[l2]) - starting[l2] + 1
            if l1 + 1 == l2:
                ans.append(one + firstLen + lastLen)
                continue
            res = max(firstLen + contiguousZero[l1 + 1], contiguousZero[l2 - 1] + lastLen, st.query(l1 + 1, l2 - 2))
            ans.append(res + one)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((s, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, queries in dataset:
        results.append(solution.maxActiveSectionsAfterTrade(s, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')