import os
import sys
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ans = 0
        min_pos = -1
        max_pos = -1
        break_pos = -1
        n = len(nums)
        for end in range(n):
            if nums[end] > maxK or nums[end] < minK:
                break_pos = end
                min_pos = -1
                max_pos = -1
            else:
                if nums[end] == minK:
                    min_pos = end
                if nums[end] == maxK:
                    max_pos = end
                if min_pos != -1 and max_pos != -1:
                    ans += min(min_pos, max_pos) - break_pos
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            minK = int(lines[1].split('=')[1].strip()[:-1])
            maxK = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, minK, maxK))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, minK, maxK in dataset:
        results.append(solution.countSubarrays(nums, minK, maxK))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')