import os
import sys
from typing import List

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n = len(nums)
        for i in range(n):
            if start - i >= 0 and nums[start - i] == target:
                return i
            if start + i < n and nums[start + i] == target:
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
            target = int(lines[1].split('=')[1].strip()[:-1])
            start = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, target, start))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, target, start in dataset:
        results.append(solution.getMinDistance(nums, target, start))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')