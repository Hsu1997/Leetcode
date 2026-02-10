import os
import sys
from typing import List

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for start in range(n):
            cnt_o = {}
            cnt_e = {}
            for k in range(start, n):
                if nums[k] % 2 == 0:
                    cnt_e[nums[k]] = cnt_e.get(nums[k], 0) + 1
                else:
                    cnt_o[nums[k]] = cnt_o.get(nums[k], 0) + 1
                if len(cnt_o) == len(cnt_e):
                    ans = max(ans, k - start + 1)
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
        results.append(solution.longestBalanced(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')