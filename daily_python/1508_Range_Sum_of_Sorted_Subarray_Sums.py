import sys
import os
from typing import List
import queue

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        pq = queue.PriorityQueue()
        for i in range(n):
            pq.put((nums[i], i))
        ans = 0
        round = 1
        mod = int(1e9+7)
        while round <= right:
            num, index = pq.get()
            if index+1 < n:
                pq.put((num + nums[index+1], index+1))
            if round >= left:
                ans = (ans + num) % mod
            round += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
            n = int(lines[1].split('=')[1].strip()[0])
            left = int(lines[2].split('=')[1].strip()[0])
            right = int(lines[3].split('=')[1].strip()[0])
            dataset.append((nums, n, left, right))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, n, left, right in dataset:
        results.append(solution.rangeSum(nums, n, left, right))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')