import os
import sys
from typing import List
from functools import cmp_to_key

class Solution:
    def compare(self, x, y):
        if str(x) + str(y) > str(y) + str(x):
            return -1
        else:
            return 1
    def largestNumber(self, nums: List[int]) -> str:
        sorted_nums = sorted(nums, key = cmp_to_key(self.compare))
        ans = ''.join(map(str, sorted_nums))
        if ans[0] == '0':
            return '0'
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
        results.append(solution.largestNumber(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')