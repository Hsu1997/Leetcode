import os
import sys
from typing import List
import heapq

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        queries = sorted(queries)
        n = len(nums)
        q = len(queries)
        j = 0
        delete = [0] * (n + 1)
        curr = 0
        candidate = []
        heapq.heapify(candidate)
        for i in range(n):
            while j < q and queries[j][0] == i:
                heapq.heappush(candidate, -queries[j][1])
                j += 1
            curr += delete[i]
            while curr < nums[i]:
                if not candidate or -candidate[0] < i:
                    return -1
                temp = -heapq.heappop(candidate)
                curr += 1
                delete[temp + 1] -= 1 
        return len(candidate)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((nums, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, queries in dataset:
        results.append(solution.maxRemoval(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')