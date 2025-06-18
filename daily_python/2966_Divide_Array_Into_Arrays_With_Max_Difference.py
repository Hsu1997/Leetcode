import os
import sys
from typing import List

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)
        nums = sorted(nums)
        ans = []
        for i in range(0, n, 3):
            if nums[i+2] - nums[i] > k:
                return []
            ans.append((nums[i], nums[i+1], nums[i+2]))
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
        results.append(solution.divideArray(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
