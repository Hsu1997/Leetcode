import os
import sys
from typing import List

class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        M = -1
        m = 10 ** 9
        n = len(nums)
        res = [0] * n
        for i in range(n):
            M = max(M, nums[i])
            res[i] = M
        for i in range(n-1, -1, -1):
            m = min(m, nums[i])
            res[i] -= m
        for i in range(n):
            if res[i] <= k:
                return i
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.firstStableIndex(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')