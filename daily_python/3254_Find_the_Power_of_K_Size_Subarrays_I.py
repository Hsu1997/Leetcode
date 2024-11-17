import os
import sys
from typing import List

class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if k == 1:
            return nums
        ans = [-1] * (n - k + 1)
        continuous = 1
        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                continuous += 1
            else:
                continuous = 1
            if continuous >= k:
                ans[i - k + 1] = nums[i]
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.resultsArray(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')