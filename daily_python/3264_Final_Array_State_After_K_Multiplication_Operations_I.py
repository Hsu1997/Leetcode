import os
import sys
import heapq
from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        n = len(nums)
        minheap = []
        for i, num in enumerate(nums):
            minheap.append((num, i))
        heapq.heapify(minheap)
        for i in range(k):
            curr, index = heapq.heappop(minheap)
            heapq.heappush(minheap, (curr * multiplier, index))
        ans = [0] * n
        while minheap:
            curr, index = heapq.heappop(minheap)
            ans[index] = curr
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            multiplier = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, k, multiplier))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k, multiplier in dataset:
        results.append(solution.getFinalState(nums, k, multiplier))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    