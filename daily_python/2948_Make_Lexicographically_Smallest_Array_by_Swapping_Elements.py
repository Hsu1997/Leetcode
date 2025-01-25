import os
import sys
from typing import List
from collections import deque

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        sorted_nums = sorted(nums)
        num_to_list = {}
        group = 0
        group_list = [deque()]
        num_to_list[sorted_nums[0]] = 0
        group_list[0].append(sorted_nums[0])
        for i in range(1, n):
            if sorted_nums[i] - sorted_nums[i-1] > limit:
                group += 1
                group_list.append(deque())
            num_to_list[sorted_nums[i]] = group
            group_list[group].append(sorted_nums[i])
        for i in range(n):
            num = nums[i]
            group = num_to_list[num]
            nums[i] = group_list[group].popleft()
        return nums
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            limit = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, limit))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, limit in dataset:
        results.append(solution.lexicographicallySmallestArray(nums, limit))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
