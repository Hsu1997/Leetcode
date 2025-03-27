import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        left = defaultdict(int)
        right = defaultdict(int)
        for i in nums:
            right[i] += 1
        for index in range(n):
            num = nums[index]
            left[num] += 1
            right[num] -= 1
            if left[num] * 2 > index + 1 and right[num] * 2 > n - 1 - index:
                return index
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
        results.append(solution.minimumIndex(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')