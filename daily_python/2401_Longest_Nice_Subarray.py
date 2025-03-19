import os
import sys
from typing import List

class Solution:
    def valid(self, left, right):
        for d in range(32):
            if self.acc_count[right][d] - self.acc_count[left][d] > 1:
                return False
        return True

    def longestNiceSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 1
        self.acc_count = [[0] * 32 for _ in range(n+1)]
        for i in range(n):
            curr = nums[i]
            for d in range(32):
                self.acc_count[i+1][d] = self.acc_count[i][d] + (1 if (curr % 2 == 1) else 0)
                curr //= 2
        left = 0
        right = 1
        while right <= n:
            if self.valid(left, right):
                ans = max(ans, right - left)
                right += 1
            else:
                left += 1
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
        results.append(solution.longestNiceSubarray(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')