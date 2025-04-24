import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        s = set(nums)
        distinct = len(s)
        curr_size = 0
        count = defaultdict(int)
        end = 0
        ans = 0
        for start in range(n):
            while end < n and curr_size < distinct:
                count[nums[end]] += 1
                if count[nums[end]] == 1:
                    curr_size += 1
                end += 1
            if curr_size < distinct:
                return ans
            ans += n - end + 1
            count[nums[start]] -= 1
            if count[nums[start]] == 0:
                curr_size -= 1
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
        results.append(solution.countCompleteSubarrays(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')