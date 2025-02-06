import os
import sys
from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        count = {}
        for i in range(n):
            for j in range(i+1, n):
                curr = nums[i] * nums[j]
                if curr not in count:
                    count[curr] = 0
                count[curr] += 1
        ans = 0
        for c in count.values():
            ans += c * (c-1) / 2
        return int(ans) * 8
    
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
        results.append(solution.tupleSameProduct(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')