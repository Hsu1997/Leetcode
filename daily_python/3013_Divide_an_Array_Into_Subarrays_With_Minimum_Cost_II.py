import os
import sys
from typing import List
from sortedcontainers import SortedList

class Container:
    def __init__(self, k):
        self.k = k
        self.st1 = SortedList()
        self.st2 = SortedList()
        self.s = 0

    def add(self, x):
        self.st1.add(x)
        self.s += x
        self.adj()

    def rm(self, x):
        if x in self.st1:
            self.st1.remove(x)
            self.s -= x
        else:
            self.st2.remove(x)
        self.adj()

    def adj(self):
        while len(self.st1) < self.k and len(self.st2) > 0:
            x = self.st2[0]
            self.st1.add(x)
            self.st2.remove(x)
            self.s += x
        while len(self.st1) > self.k:
            x = self.st1[-1]
            self.st1.remove(x)
            self.s -= x
            self.st2.add(x)

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        c = Container(k-1)
        for i in range(1, k):
            c.add(nums[i])
        currSum = c.s
        
        for i in range(k, len(nums)):
            d = i - dist - 1
            if d > 0:
                c.rm(nums[d])
            c.add(nums[i])
            currSum = min(currSum, c.s)
        return nums[0] + currSum
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dist = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, k, dist))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k, dist in dataset:
        results.append(solution.minimumCost(nums, k, dist))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')