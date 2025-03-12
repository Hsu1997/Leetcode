import os
import sys
from typing import List

class Solution:
    def lower_bound(self, nums, num):
        n = len(nums)
        left = 0
        right = n-1
        index = n
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] >= num:
                index = mid
                right = mid - 1
            else:
                left = mid + 1
        return index
    
    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)
        if nums[0] > 0 or nums[n-1] < 0:
            return n
        pos = n - self.lower_bound(nums, 1)
        neg = self.lower_bound(nums, 0)
        return max(pos, neg)

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
        results.append(solution.maximumCount(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')