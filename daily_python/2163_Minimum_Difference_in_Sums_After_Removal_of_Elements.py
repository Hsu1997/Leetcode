import sys
import os
from typing import List
import heapq

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        k = n // 3
        left = [0] * n
        right = [0] * n
        lpq = []
        rpq = []
        lacc = 0
        racc = 0
        for i in range(n):
            lacc += nums[i]
            heapq.heappush(lpq, - nums[i])
            if len(lpq) > k:
                lacc += heapq.heappop(lpq)
            left[i] = lacc
        for i in range(n-1, -1, -1):
            racc += nums[i]
            heapq.heappush(rpq, nums[i])
            if len(rpq) > k:
                racc -= heapq.heappop(rpq)
            right[i] = racc
        ans = float('inf')
        for i in range(k - 1, n - k):
            ans = min(ans, left[i] - right[i+1])
        return ans
    
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
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minimumDifference(nums))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
