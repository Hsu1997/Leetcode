import os
import sys
from typing import List, Optional

class Solution:
    def _digitSum(self, num):
        sum = 0
        while num:
            sum += num % 10
            num //= 10
        return sum
    def maximumSum(self, nums: List[int]) -> int:
        ans = -1
        digit = [0] * 82
        for num in nums:
            digitSum = self._digitSum(num)
            if digit[digitSum]:
                ans = max(ans, digit[digitSum] + num)
            digit[digitSum] = max(digit[digitSum], num)
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
        results.append(solution.maximumSum(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')