import os
import sys
from typing import List

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        ans = -1
        ptr = 0
        for i in range(n1):
            while ptr + 1 < n2 and nums2[ptr + 1] >= nums1[i]:
                ptr += 1
            ans = max(ans, ptr - i)
        return max(ans, 0)
    
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
        results.append(solution.maxDistance(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')