import os
import sys
from typing import List

class Solution:
    def lower_bound(self, lis: List[int], target: int) -> int:
        left = 0
        right = len(lis)-1
        while(left < right):
            mid = (left + right) // 2
            if lis[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left
    
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        left_to_right = [1] * n
        temp = [nums[0]]
        for i in range(1, n):
            curr = nums[i]
            if curr > temp[-1]:
                temp.append(curr)
            else:
                index = self.lower_bound(temp, curr)
                temp[index] = curr
            left_to_right[i] = len(temp)
        temp = [nums[-1]]
        right_to_left = [1] * n
        for i in range(n-1, -1, -1):
            curr = nums[i]
            if curr > temp[-1]:
                temp.append(curr)
            else:
                index = self.lower_bound(temp, curr)
                temp[index] = curr
            right_to_left[i] = len(temp)
        ans = n
        for i, j in zip(left_to_right, right_to_left):
            if i > 1 and j > 1:
                ans = min(ans, n - i - j + 1)
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

if __name__ == "__main__":
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minimumMountainRemovals(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')