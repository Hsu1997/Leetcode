import os
import sys
from typing import List
from math import sqrt

class Solution:
    def is_prime(self, n):
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def primeSubOperation(self, nums: List[int]) -> bool:
        M = max(nums)
        lastest_prime = [0] * (M + 1)
        lastest = -1
        for i in range(M, 1, -1):
            lastest_prime[i] = lastest
            if self.is_prime(i):
                lastest = i
        lastest_prime[0] = 2
        lastest_prime[1] = 2
        n = len(nums)
        for i in range(n - 2, -1, -1):
            d = nums[i] - nums[i+1]
            if d < 0:
                continue
            if lastest_prime[d] == -1:
                return False
            nums[i] -= lastest_prime[d]
            if nums[i] <= 0:
                return False
        return True

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
        results.append(solution.primeSubOperation(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')