import os
import sys
from typing import List

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        acc = 0
        M = (1 << maximumBit) - 1
        ans = [0] * n
        for i in range(n):
            acc ^= nums[i]
            ans[n-1-i] = acc ^ M
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            maximumBit = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, maximumBit))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, maximumBit in dataset:
        results.append(solution.getMaximumXor(nums, maximumBit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')