import os
import sys
from typing import List
from heapq import heapify, heappop, heappush

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        b = n.bit_length() - 1
        stMin = [[0] * (b + 1) for _ in range(n)]
        stMax = [[0] * (b + 1) for _ in range(n)]
        for start in range(n):
            stMin[start][0] = nums[start]
            stMax[start][0] = nums[start]
        for l in range(1, b + 1):
            for start in range(n):
                if start + (1 << (l - 1)) >= n:
                    continue
                stMin[start][l] = min(stMin[start][l-1], stMin[start + (1 << (l - 1))][l-1])
                stMax[start][l] = max(stMax[start][l-1], stMax[start + (1 << (l - 1))][l-1])
        def query(l: int, r: int) -> int:
            j = (r - l + 1).bit_length() - 1
            m = min(stMin[l][j], stMin[r - (1 << j) + 1][j])
            M = max(stMax[l][j], stMax[r - (1 << j) + 1][j])
            return M - m
        pq = [(-query(i, n - 1), i, n - 1) for i in range(n)]
        heapify(pq)
        ans = 0
        for _ in range(k):
            v, l, r = heappop(pq)
            ans += v
            if l < r:
                heappush(pq, (-query(l, r - 1), l, r - 1))
        return -ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.maxTotalValue(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')