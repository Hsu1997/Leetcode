import os
import sys
from typing import List

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        ptr1, ptr2 = 0, 0
        while ptr1 < n1 and ptr2 < n2:
            if nums1[ptr1] == nums2[ptr2]:
                return nums1[ptr1]
            if nums1[ptr1] < nums2[ptr2]:
                ptr1 += 1
            else:
                ptr2 += 1
        return -1

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
        results.append(solution.getCommon(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')