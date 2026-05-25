import os
import sys
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            m = (l + r) // 2
            if nums[m] < nums[r]:
                r = m
            else:
                l = m + 1
        d = r
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) // 2
            if nums[(m + d) % n] == target:
                return (m + d) % n
            if nums[(m + d) % n] < target:
                l = m + 1
            else:
                r = m - 1
        return -1
    
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
        results.append(solution.search(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')