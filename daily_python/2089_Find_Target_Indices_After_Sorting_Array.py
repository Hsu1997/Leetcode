import os
import sys
from typing import List

class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        cnt1 = 0
        cnt2 = 0
        for i in nums:
            if i < target:
                cnt1 += 1
            elif i > target:
                cnt2 += 1
            else:
                continue
        return [i for i in range(cnt1, len(nums) - cnt2)]
    
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
        results.append(solution.targetIndices(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')