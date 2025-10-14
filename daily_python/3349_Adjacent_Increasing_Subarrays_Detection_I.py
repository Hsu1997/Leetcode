import os
import sys
from typing import List

class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        cnt = 1
        precnt = 0
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                cnt += 1
            else:
                precnt = cnt
                cnt = 1
            if (precnt >= k and cnt >= k) or cnt >= 2 * k:
                return True
        return False

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
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
        results.append(solution.hasIncreasingSubarrays(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')