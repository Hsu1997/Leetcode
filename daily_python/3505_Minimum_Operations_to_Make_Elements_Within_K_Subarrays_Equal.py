import os
import sys
from typing import List
from sortedcontainers import SortedList

class SortedMedian:
    def __init__(self):
        self.lo = SortedList()
        self.hi = SortedList()
        self.sum1 = 0
        self.sum2 = 0

    def get(self) -> int:
        return self.hi[0]

    def balance(self) -> None:
        while len(self.lo) > len(self.hi):
            value = self.lo.pop()
            self.sum1 -= value
            self.sum2 += value
            self.hi.add(value)

        while len(self.lo) + 1 < len(self.hi):
            value = self.hi.pop(0)
            self.sum2 -= value
            self.sum1 += value
            self.lo.add(value)

    def add(self, value: int) -> None:
        if not self.hi or value >= self.get():
            self.hi.add(value)
            self.sum2 += value
        else:
            self.lo.add(value)
            self.sum1 += value
        self.balance()

    def delete(self, value: int) -> None:
        if value < self.get():
            self.lo.remove(value)
            self.sum1 -= value
        else:
            self.hi.remove(value)
            self.sum2 -= value
        self.balance()


class Solution:
    def minOperations(self, nums: list[int], x: int, k: int) -> int:
        n = len(nums)
        oper = [0] * n
        sm = SortedMedian()

        for i, value in enumerate(nums):
            sm.add(value)
            if i >= x:
                sm.delete(nums[i - x])
            if i >= x - 1:
                med = sm.get()
                oper[i] = med * len(sm.lo) - sm.sum1 + sm.sum2 - med * len(sm.hi)
        dp = [0] * n

        for j in range(1, k + 1):
            start = j * x - 1
            res = [-1] * n
            for i in range(start, n):
                res[i] = oper[i] + (dp[i - x] if i >= x else 0)
                if i > 0 and res[i - 1] >= 0:
                    res[i] = min(res[i], res[i - 1])
            dp = res
        return dp[n - 1]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            x = int(lines[1].split('=')[1].strip()[:-1])
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, x, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, x, k in dataset:
        results.append(solution.minOperations(nums, x, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')