import os
import sys
from typing import List
import heapq

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        pq = []
        curr_max = -1e6
        for i, l in enumerate(nums):
            pq.append((nums[i][0], (i, 0)))
            curr_max = max(curr_max, nums[i][0])
        heapq.heapify(pq)
        ans_start = 0
        ans_len = 1e6
        while pq:
            num, (l, idx) = heapq.heappop(pq)
            if curr_max - num < ans_len:
                ans_start = num
                ans_len = curr_max - num
            if idx + 1 == len(nums[l]):
                return [ans_start, ans_start + ans_len]
            curr_max = max(curr_max, nums[l][idx+1])
            heapq.heappush(pq, (nums[l][idx+1], (l, idx+1)))
        return (-1, -1)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.smallestRange(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')