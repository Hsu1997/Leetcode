import os
import sys
from typing import List

class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n1, n2 = len(nums1), len(nums2)
        pos1, pos2 = 0, 0
        while pos1 < n1 and nums1[pos1] < 0:
            pos1 += 1
        while pos2 < n2 and nums2[pos2] < 0:
            pos2 += 1
        def count(threshold):
            cnt = 0
            i, j = 0, pos2 - 1
            while i < pos1 and j >= 0:
                if nums1[i] * nums2[j] > threshold:
                    i += 1
                else:
                    cnt += pos1 - i
                    j -= 1
            i, j = pos1, n2 - 1
            while i < n1 and j >= pos2:
                if nums1[i] * nums2[j] > threshold:
                    j -= 1
                else:
                    cnt += j - pos2 + 1
                    i += 1
            i, j = 0, pos2
            while i < pos1 and j < n2:
                if nums1[i] * nums2[j] > threshold:
                    j += 1
                else:
                    cnt += n2 - j
                    i += 1
            i, j = pos1, 0
            while i < n1 and j < pos2:
                if nums1[i] * nums2[j] > threshold:
                    i += 1
                else:
                    cnt += n1 - i
                    j += 1
            return cnt
        left = min(nums1[0] * nums2[0], nums1[0] * nums2[-1], nums1[-1] * nums2[0], nums1[-1] * nums2[-1])
        right = max(nums1[0] * nums2[0], nums1[0] * nums2[-1], nums1[-1] * nums2[0], nums1[-1] * nums2[-1])
        ans = right
        while left <= right:
            mid = (left + right) // 2
            if count(mid) < k:
                left = mid + 1
            else:
                ans = min(ans, mid)
                right = mid - 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            nums2 = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums1, nums2, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums1, nums2, k in dataset:
        results.append(solution.kthSmallestProduct(nums1, nums2, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')