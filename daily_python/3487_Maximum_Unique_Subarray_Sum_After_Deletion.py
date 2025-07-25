import os
import sys
from typing import List

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = 0
        M = float('-inf')
        cnt = set()
        for i in nums:
            if i not in cnt and i >= 0:
                ans += i
            cnt.add(i)
            M = max(M, i)
        if ans == 0:
            return M
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
        results.append(solution.maxSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')