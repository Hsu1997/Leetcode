import os
import sys
from typing import List

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        if min(nums1) % 2 == 1:
            return True
        return all(i % 2 == 0 for i in nums1)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums1)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums1 in dataset:
        results.append(solution.uniformArray(nums1))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')