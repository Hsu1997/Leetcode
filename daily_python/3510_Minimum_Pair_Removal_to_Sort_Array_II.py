import os
import sys
from typing import List
import heapq

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        prev = [i - 1 for i in range(n)]
        next = [i + 1 for i in range(n)]
        next[n-1] = -1
        version = [0] * n
        op = 0
        bad = sum(1 if nums[i] > nums[i + 1] else 0 for i in range(n - 1))
        pq = [(nums[i] + nums[i+1], i, 0) for i in range(n - 1)]
        heapq.heapify(pq)
        while bad > 0:
            while pq:
                _, i, v = heapq.heappop(pq)
                j = next[i]
                if i == -1 or j == -1 or v != version[i]:
                    continue
                p = prev[i]
                q = next[j]
                break
            # p (i j) q
            if nums[i] > nums[j]:
                bad -= 1
            if p != -1 and nums[p] > nums[i]:
                bad -= 1
            if q != -1 and nums[j] > nums[q]:
                bad -= 1
            
            nums[i] += nums[j]
            version[i] += 1
            version[j] += 1
            next[i] = q
            if q != -1:
                prev[q] = i
            
            if p != -1 and nums[p] > nums[i]:
                bad += 1
            if q != -1 and nums[i] > nums[q]:
                bad += 1
            
            if p != -1:
                version[p] += 1
                heapq.heappush(pq, (nums[p] + nums[i], p, version[p]))
            if q != -1:
                heapq.heappush(pq, (nums[i] + nums[q], i, version[i]))
            
            op += 1
        return op

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
        results.append(solution.minimumPairRemoval(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')