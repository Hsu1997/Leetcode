import os
import sys
from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        v1, v2 = -1, -1
        for num in nums:
            if num > v1:
                v2 = v1
                v1 = num
            else:
                v2 = max(v2, num)
        return (v1 - 1) * (v2 - 1)

def readData(filename):
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
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    solution = Solution()
    results = []
    for nums in dataset:
        results.append(solution.maxProduct(nums))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')