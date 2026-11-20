import os
import sys
from typing import List

class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        mx1 = mx2 = mx3 = 0
        mn1 = mn2 = mn3 = float('inf')
        for x in nums:
            if x > mx1:
                mx1, mx2, mx3 = x, mx1, mx2
            elif x > mx2:
                mx2, mx3 = x, mx2
            elif x > mx3:
                mx3 = x

            if x < mn1:
                mn1, mn2, mn3 = x, mn1, mn2
            elif x < mn2:
                mn2, mn3 = x, mn2
            elif x < mn3:
                mn3 = x
        return min(mx1 - mn3, mx2 - mn2, mx3 - mn1)

def readDatSet(filename):
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
    dataset = readDatSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minimizeSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')