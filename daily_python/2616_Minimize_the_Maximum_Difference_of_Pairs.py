import os
import sys
from typing import List

class Solution:
    def valid(self, nums, p, d):
        if p == 0:
            return True
        idx = 0
        found = 0
        while idx < self.n - 1:
            if abs(nums[idx] - nums[idx + 1]) <= d:
                found += 1
                idx += 2
                if found >= p:
                    return True
            else:
                idx += 1
        return False
    
    def minimizeMax(self, nums: List[int], p: int) -> int:
        self.n = len(nums)
        nums = sorted(nums)
        left = 0
        right = nums[-1] - nums[0]
        ans = float('inf')
        while left <= right:
            mid = (left + right) // 2
            if self.valid(nums, p, mid):
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
            p = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, p))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, p in dataset:
        results.append(solution.minimizeMax(nums, p))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')