import sys
import os
from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l, r, ptr = 0, n-1, 0
        while ptr <= r:
            if nums[ptr] == 0:
                nums[l], nums[ptr] = nums[ptr], nums[l]
                l += 1
                ptr += 1
            elif nums[ptr] == 1:
                ptr += 1
            else:
                nums[ptr], nums[r] = nums[r], nums[ptr]
                r -= 1
        return
        

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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        solution.sortColors(nums)
        results.append(nums)
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')