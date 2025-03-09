import os
import sys
from typing import List
import heapq

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        ans = 0
        while nums[0] < k:
            a = heapq.heappop(nums)
            b = heapq.heappop(nums)
            heapq.heappush(nums, a * 2 + b)
            ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.minOperations(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')