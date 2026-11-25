import os
import sys
from typing import List

class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        p = [0] * (n + 1)
        h = [0] * (n + 1)
        mod = 10**9 + 7
        base = 738591737
        p[0] = 1
        for i in range(n):
            p[i+1] = p[i] * base % mod
            h[i+1] = (h[i] * base + nums[i]) % mod
        def check(l) -> bool:
            cnt = {}
            for start in range(0, n - l + 1):
                end = start + l
                res = (h[end] - h[start] * p[l]) % mod
                cnt[res] = cnt.get(res, 0) + 1
            for c in cnt.values():
                if c == 1:
                    return True
            return False
        left = 1
        right = n
        ans = n
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans

def readDataSet(filename):
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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.smallestUniqueSubarray(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')