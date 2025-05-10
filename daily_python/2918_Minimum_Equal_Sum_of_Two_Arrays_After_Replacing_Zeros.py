import os
import sys
from typing import List

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2, zero1, zero2 = 0, 0, 0, 0
        for i in nums1:
            s1 += i
            if i == 0:
                zero1 = True
                s1 += 1
        for i in nums2:
            s2 += i
            if i == 0:
                zero2 = True
                s2 += 1
        if (not zero1 and s1 < s2) or (not zero2 and s2 < s1):
            return -1
        return max(s1, s2)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            nums2 = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((nums1, nums2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums1, nums2 in dataset:
        results.append(solution.minSum(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')