import os
import sys
from typing import List

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        one, two, three = [0] * 2048, [0] * 2048, [0] * 2048
        for num in nums:
            one[num] = 1
        for num in nums:
            for v in range(2048):
                if one[v]:
                    two[v ^ num] = 1
        for num in nums:
            for v in range(2048):
                if two[v]:
                    three[v ^ num] = 1
        ans = sum(three)
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
        results.append(solution.uniqueXorTriplets(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')