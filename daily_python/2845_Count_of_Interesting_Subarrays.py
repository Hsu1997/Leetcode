import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        n = len(nums)
        ans = 0
        curr = 0
        cnt = defaultdict(int)
        cnt[0] = 1

        for num in nums:
            if num % modulo == k:
                curr = (curr + 1) % modulo
            ans += cnt[(curr - k + modulo) % modulo]
            cnt[curr] += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            modulo = int(lines[1].split('=')[1].strip()[:-1])
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, modulo, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, modulo, k in dataset:
        results.append(solution.countInterestingSubarrays(nums, modulo, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')