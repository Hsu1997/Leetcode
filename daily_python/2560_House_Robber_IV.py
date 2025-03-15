import os
import sys
from typing import List

class Solution:
    def valid(self, nums, k, val):
        count = 0
        idx = 0
        n = len(nums)
        while idx < n:
            if nums[idx] <= val:
                count += 1
                idx += 1
            if count == k:
                return True
            idx += 1
        return False
    
    def minCapability(self, nums: List[int], k: int) -> int:
        left = 1
        right = max(nums)
        ans = float('inf')
        while left <= right:
            mid = (left + right) // 2
            if self.valid(nums, k, mid):
                ans = min(ans, mid)
                right = mid - 1
            else:
                left = mid + 1
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
        results.append(solution.minCapability(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')