import os
import sys
from typing import List

class Solution:
    def distributable(self, nums, num, maxOperations):
        operation = 0
        for n in nums:
            operation += (n + num - 1) // (num) - 1
            if operation > maxOperations:
                return False
        return True
    
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left = 1
        right = max(nums)
        ans = right
        while left < right:
            mid = (left + right) // 2
            if self.distributable(nums, mid, maxOperations):
                ans = mid
                right = mid
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
            Operations = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, Operations))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, Operations in dataset:
        results.append(solution.minimumSize(nums, Operations))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')