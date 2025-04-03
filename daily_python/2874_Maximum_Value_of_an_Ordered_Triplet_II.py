import os
import sys
from typing import List

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, M, d = 0, 0, 0
        n = len(nums)
        for i in range(n):
            ans = max(ans, nums[i] * d)
            d = max(d, M - nums[i])
            M = max(M, nums[i])
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
        results.append(solution.maximumTripletValue(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')