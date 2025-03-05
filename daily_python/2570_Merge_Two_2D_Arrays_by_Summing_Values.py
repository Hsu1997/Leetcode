import os
import sys
from typing import List

class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        n1 = len(nums1)
        n2 = len(nums2)
        idx1 = 0
        idx2 = 0
        ans = []
        while idx1 < n1 and idx2 < n2:
            if nums1[idx1][0] == nums2[idx2][0]:
                ans.append([nums1[idx1][0], nums1[idx1][1] + nums2[idx2][1]])
                idx1 += 1
                idx2 += 1
            elif nums1[idx1][0] < nums2[idx2][0]:
                ans.append([nums1[idx1][0], nums1[idx1][1]])
                idx1 += 1
            else:
                ans.append([nums2[idx2][0], nums2[idx2][1]])
                idx2 += 1
        while idx1 < n1:
            ans.append([nums1[idx1][0], nums1[idx1][1]])
            idx1 += 1
        while idx2 < n2:
            ans.append([nums2[idx2][0], nums2[idx2][1]])
            idx2 += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums1 = [list(map(int, pair.split(','))) for pair in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            nums2 = [list(map(int, pair.split(','))) for pair in lines[1].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.mergeArrays(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')