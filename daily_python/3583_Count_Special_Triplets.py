import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        left = defaultdict(int)
        right = defaultdict(int)
        ans = 0
        mod = 10 ** 9 + 7
        for i in nums:
            right[i] += 1
        for i in nums:
            right[i] -= 1
            l = left[i * 2]
            r = right[i * 2]
            ans = (ans + l * r) % mod
            left[i] += 1
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
        results.append(solution.specialTriplets(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')