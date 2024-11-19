import os
import sys
from typing import List
from collections import deque

class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = n + 1
        prefix = [0] * (n + 1)
        idx = deque()
        for i in range(1, n + 1):
            prefix[i] = prefix[i-1] + nums[i-1]
        for i in range(n + 1):
            while idx and prefix[i] - prefix[idx[0]] >= k:
                ans = min(ans, i - idx.popleft())
            while idx and prefix[i] <= prefix[idx[-1]]:
                idx.pop()
            idx.append(i)
        return ans if ans < n + 1 else -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1][:-1])
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
        results.append(solution.shortestSubarray(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')