import os
import sys
from typing import List
from collections import defaultdict

mx = 1000001
factors = [[] for _ in range(mx)]
for i in range(2, mx):
    if not factors[i]:
        for j in range(i, mx, i):
            factors[j].append(i)

class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        primePos = defaultdict(list)
        for i, x in enumerate(nums):
            if len(factors[x]) == 1 and factors[x][0] == x:
                primePos[x].append(i)
        res = 0
        seen = [False] * n
        seen[n-1] = True
        reachable = [n-1]
        while True:
            temp = []
            for x in reachable:
                if x == 0:
                    return res
                if x > 0 and not seen[x-1]:
                    temp.append(x-1)
                    seen[x-1] = True
                if x+1 < n and not seen[x+1]:
                    temp.append(x+1)
                    seen[x+1] = True
                for factor in factors[nums[x]]:
                    if factor in primePos:
                        for pos in primePos[factor]:
                            if not seen[pos]:
                                temp.append(pos)
                                seen[pos] = True
                        primePos[factor].clear()
            reachable = temp
            res += 1
        return -1

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
        results.append(solution.minJumps(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')