import os
import sys
from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0]
        s1 = 100
        s2 = 100
        for i in nums[1:]:
            if i < s2:
                s2 = max(i, s1)
                s1 = min(i, s1)
        ans += s1 + s2
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
        results.append(solution.minimumCost(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    