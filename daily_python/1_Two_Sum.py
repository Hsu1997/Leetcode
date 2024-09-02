import os
import sys
from typing import List
import collections

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = collections.defaultdict(lambda : -1)
        for index, num in enumerate(nums):
            if d[target - num] != -1:
                return [d[target - num], index]
            else:
                d[num] = index
        return [-1,-1]

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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, target in dataset:
        results.append(solution.twoSum(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
