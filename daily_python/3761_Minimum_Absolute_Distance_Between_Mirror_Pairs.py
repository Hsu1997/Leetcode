import os
import sys
from typing import List

class Solution:
    def reverse(self, num: int) -> int:
        res = 0
        while num:
            res = res * 10 + (num % 10)
            num //= 10
        return res
    
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        n = len(nums)
        m = {}
        ans = n
        for i in range(n):
            if nums[i] in m:
                ans = min(ans, i - m[nums[i]])
            m[self.reverse(nums[i])] = i
        return ans if ans < n else -1
    
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
        results.append(solution.minMirrorPairDistance(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')