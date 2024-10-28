import os
import sys
from typing import List

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums.sort()
        c = {}
        for i in nums:
            root = i**(0.5)
            if root * root == i and root in c:
                c[i] = c[root] + 1
            else:
                c[i] = 1
        ans = max(c.values())
        return ans if ans > 1 else -1
    
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
        results.append(solution.longestSquareStreak(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')