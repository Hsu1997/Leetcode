import os
import sys
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        odd = 0
        even = 0
        cross = 0
        prev = -1
        for num in nums:
            if num % 2 == 0:
                even += 1
            else:
                odd += 1
            if num % 2 != prev:
                cross += 1
                prev = num % 2
        return max(odd, even, cross)

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
        results.append(solution.maximumLength(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')