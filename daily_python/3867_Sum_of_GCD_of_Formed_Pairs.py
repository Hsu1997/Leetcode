import os
import sys
from typing import List

class Solution:
    def gcd(self, a: int, b: int) -> int:
        return a if b == 0 else self.gcd(b, a % b)
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        mv = 0
        res = []
        for i in range(n):
            mv = max(mv, nums[i])
            res.append(self.gcd(nums[i], mv))
        res.sort()
        ans = 0
        for i in range(n // 2):
            ans += self.gcd(res[i], res[n-1-i])
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
        results.append(solution.gcdSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')