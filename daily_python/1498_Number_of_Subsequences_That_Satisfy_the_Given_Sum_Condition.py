import os
import sys
from typing import List

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        n = len(nums)
        mod = 10**9 + 7
        nums.sort()
        p = [1] * n
        for i in range(1, n):
            p[i] = (p[i-1] * 2) % mod
        ptr = n - 1
        ans = 0
        for i in range(n):
            while ptr >= 0 and nums[i] + nums[ptr] > target:
                ptr -= 1
            if i > ptr:
                break
            ans = (ans + p[ptr - i]) % mod
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            target = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, target in dataset:
        results.append(solution.numSubseq(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')