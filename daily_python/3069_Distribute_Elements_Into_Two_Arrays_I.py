import os
import sys
from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        ptr1, ptr2 = 0, n - 1
        ans[ptr1] = nums[0]
        ans[ptr2] = nums[1]
        for i in range(2, n):
            if ans[ptr1] > ans[ptr2]:
                ptr1 += 1
                ans[ptr1] = nums[i]
            else:
                ptr2 -= 1
                ans[ptr2] = nums[i]
        ans[ptr2:] = ans[ptr2:][::-1]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
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
        results.append(solution.resultArray(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')