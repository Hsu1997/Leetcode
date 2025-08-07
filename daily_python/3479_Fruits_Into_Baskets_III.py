import os
import sys
from typing import List

class SegmentTree:
    def __init__(self, nums):
        self.d = 1
        n = len(nums)
        while n:
            self.d <<= 1
            n //= 2
        self.t = [0] * (self.d * 2)
        for i in range(len(nums)):
            self.t[self.d + i] = nums[i]
        for i in range(self.d - 1, 0, -1):
            self.t[i] = max(self.t[i * 2], self.t[i * 2 + 1])
    def change(self, pos, val):
        pos += self.d
        self.t[pos] = val
        pos //= 2
        while pos > 0:
            self.t[pos] = max(self.t[pos * 2], self.t[pos * 2 + 1])
            pos //= 2
    def find_leftmost_pos(self, val):
        pos = 1
        while pos < self.d:
            if self.t[pos] < val:
                return -1
            if self.t[pos * 2] >= val:
                pos = pos * 2 
            else:
                pos = pos * 2 + 1
        return pos - self.d
    
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        ST = SegmentTree(baskets)
        ans = 0
        for fruit in fruits:
            p = ST.find_leftmost_pos(fruit)
            if p == -1:
                ans += 1
            else:
                ST.change(p, 0)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            fruits = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            baskets = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((fruits, baskets))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for fruits, baskets in dataset:
        results.append(solution.numOfUnplacedFruits(fruits, baskets))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')