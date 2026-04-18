import os
import sys
from typing import List

class Solution:
    def mirrorDistance(self, n: int) -> int:
        def rev(x):
            res = 0
            while x:
                res = res * 10 + (x % 10)
                x //= 10
            return res
        return abs(n - rev(n))

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = int(lines[0].split('=')[1].strip()[:-1])
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
        results.append(solution.mirrorDistance(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')