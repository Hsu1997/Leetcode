import os
import sys
from typing import List

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        target = total_sum % p
        if target == 0:
            return 0
        last_pos = {0 : -1}
        temp_sum = 0
        ans = len(nums)
        for i, num in enumerate(nums):
            temp_sum = (temp_sum + num) % p
            needed = (temp_sum - target + p) % p
            if needed in last_pos:
                ans = min(ans, i - last_pos[needed])
            last_pos[temp_sum] = i
        return -1 if ans == len(nums) else ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            p = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, p))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, p in dataset:
        results.append(solution.minSubarray(nums, p))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')