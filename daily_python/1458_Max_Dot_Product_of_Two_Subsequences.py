import os
import sys
from typing import List

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        dp = [[0] * n for _ in range(m)]
        acc = [[0] * n for _ in range(m)]
        dp[0][0] = nums1[0] * nums2[0]
        acc[0][0] = dp[0][0]
        for i in range(1, m):
            dp[i][0] = nums1[i] * nums2[0]
            acc[i][0] = max(acc[i-1][0], dp[i][0])
        for j in range(1, n):
            dp[0][j] = nums1[0] * nums2[j]
            acc[0][j] = max(acc[0][j-1], dp[0][j])
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = nums1[i] * nums2[j] + max(0, acc[i-1][j-1])
                acc[i][j] = max(acc[i-1][j], acc[i][j-1], dp[i][j])
        return acc[m-1][n-1]
    
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
        results.append(solution.maxDotProduct(nums1, nums2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')