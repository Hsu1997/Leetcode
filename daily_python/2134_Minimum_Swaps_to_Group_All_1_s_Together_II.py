import sys
import os
from typing import List
import ast

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        one = nums.count(1)
        n = len(nums)
        count = nums[:one].count(1)
        ans = one - count
        for i in range(n):
            deletion = i
            addition = (i + one) % n
            count = count - (nums[deletion] == 1) + (nums[addition] == 1)
            ans = min(ans, one - count)
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n')
        for block in blocks:
            data = map(int,block.split('=')[1][:-1].strip().strip('{').strip('}').split(','))
            dataset.append(list(data))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minSwaps(nums))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
