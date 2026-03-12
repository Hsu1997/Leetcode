import os
import sys
from typing import List

class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        ans = float('-inf')
        ptr1 = 1
        ptr2 = 1
        while ptr1 + 2 < n:
            flag = True
            while ptr1+1 < n and not (nums[ptr1-1] < nums[ptr1] and nums[ptr1] > nums[ptr1+1]):
                if nums[ptr1-1] == nums[ptr1]:
                    flag = False
                    break
                ptr1 += 1
            if not flag:
                ptr1 += 1
                continue
            ptr2 = ptr1 + 1
            if ptr2 + 1 >= n:
                return ans
            while ptr2+1 < n and not (nums[ptr2-1] > nums[ptr2] and nums[ptr2] < nums[ptr2+1]):
                if nums[ptr2-1] == nums[ptr2]:
                    flag = False
                    break
                ptr2 += 1
            if not flag:
                ptr1 = ptr2 + 1
                continue
            acc = 0
            for i in range(ptr1, ptr2 + 1):
                acc += nums[i]
            prevacc, nextacc, prevMax, nextMax = 0, 0, float('-inf'), float('-inf')
            tempptr = ptr1 - 1
            while tempptr >= 0 and nums[tempptr] < nums[tempptr+1]:
                prevacc += nums[tempptr]
                prevMax = max(prevMax, prevacc)
                tempptr -= 1
            tempptr = ptr2 + 1
            while tempptr < n and nums[tempptr] > nums[tempptr-1]:
                nextacc += nums[tempptr]
                nextMax = max(nextMax, nextacc)
                tempptr += 1
            acc += prevMax + nextMax
            ans = max(ans, acc)
            ptr1 = tempptr - 1
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
        results.append(solution.maxSumTrionic(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')