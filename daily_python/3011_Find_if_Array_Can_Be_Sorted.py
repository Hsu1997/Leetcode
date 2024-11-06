import os
import sys
from typing import List

class Solution:
    def bit_set(self, i):
        ans = 0
        while i:
            if i % 2:
                ans += 1
            i //= 2
        return ans
    
    def canSortArray(self, nums: List[int]) -> bool:
        prev_m = 0
        curr_m = 0
        bit_count = 0
        for i in nums:
            c = self.bit_set(i)
            if c == bit_count:
                curr_m = max(curr_m, i)
            else:
                prev_m = curr_m
                curr_m = i
                bit_count = c
            if i < prev_m:
                return False
        return True
    
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
        results.append(solution.canSortArray(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')