import sys
import os
from typing import List

class Solution:
    def count(self, nums: List[int], dis: int)-> int:
        ans = 0
        left = 0
        for right in range(len(nums)):
            while nums[right] - nums[left] > dis:
                left += 1
            ans += right - left
        return ans

    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        right = nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            if self.count(nums, mid) < k:
                left = mid + 1
            else:
                right = mid
        return left
        

def readDataSet(filename: str):
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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.smallestDistancePair(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')