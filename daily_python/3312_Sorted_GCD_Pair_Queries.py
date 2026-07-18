import os
import sys
from typing import List
from bisect import bisect_left

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        m = max(nums)
        cnt = [0] * (m + 1)
        for num in nums:
            cnt[num] += 1
        for i in range(1, m + 1):
            for j in range(i * 2, m + 1, i):
                cnt[i] += cnt[j]
        for i in range(1, m + 1):
            cnt[i] = cnt[i] * (cnt[i] - 1) // 2
        for i in range(m, 0, -1):
            for j in range(i * 2, m + 1, i):
                cnt[i] -= cnt[j]
        for i in range(2, m + 1):
            cnt[i] += cnt[i-1]
        ans = []
        for q in queries:
            ans.append(bisect_left(cnt, q + 1))
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((nums, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, queries in dataset:
        results.append(solution.gcdValues(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')