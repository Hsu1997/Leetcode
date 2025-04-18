import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        curr_good = 0
        count = defaultdict(int)
        end = 0
        for start in range(n):
            while end < n and curr_good < k:
                curr_good += count[nums[end]]
                count[nums[end]] += 1
                end += 1
            if curr_good < k:
                return ans
            ans += n - end + 1
            count[nums[start]] -= 1
            curr_good -= count[nums[start]]
        return ans

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
        results.append(solution.countGood(nums, k))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')