import os
import sys
from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        ans = 0
        acc = 0
        visited = [0] * 10001
        ptr = 0
        for i in nums:
            if visited[i]:
                while nums[ptr] != i:
                    visited[nums[ptr]] = 0
                    acc -= nums[ptr]
                    ptr += 1
                visited[nums[ptr]] = 0
                acc -= nums[ptr]
                ptr += 1
            visited[i] = 1
            acc += i
            ans = max(ans, acc)
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
        results.append(solution.maximumUniqueSubarray(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')