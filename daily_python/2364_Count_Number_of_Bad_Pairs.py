import os
import sys
from typing import List

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        ans = int(n * (n-1) / 2)
        count = {}
        for i in range(n):
            ans -= count.get(i - nums[i], 0)
            count[i - nums[i]] = count.get(i - nums[i], 0) + 1
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
        results.append(solution.countBadPairs(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')