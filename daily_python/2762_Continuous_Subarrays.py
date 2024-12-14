import os
import sys
from typing import List

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        freq = {}
        ans = 0
        start = 0
        for end in range(len(nums)):
            freq[nums[end]] = freq.get(nums[end], 0) + 1
            while max(freq) - 2 > min(freq):
                freq[nums[start]] -= 1
                if freq[nums[start]] == 0:
                    del freq[nums[start]]
                start += 1
            ans += end - start + 1
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
        results.append(solution.continuousSubarrays(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    