import os
import sys
from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        farrest = []
        curr = 0
        for i in range(n):
            curr = max(curr, i)
            while curr < n - 1 and nums[curr + 1] - nums[curr] <= maxDiff:
                curr += 1
            farrest.append(curr)
        ans = []
        for query in queries:
            s = min(query[0], query[1])
            e = max(query[0], query[1])
            ans.append(farrest[s] >= e)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            nums = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            maxDiff = int(lines[2].split('=')[1].strip()[:-1])
            queries = [list(map(int, building.split(','))) for building in lines[3].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, nums, maxDiff, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, nums, maxDiff, queries in dataset:
        results.append(solution.pathExistenceQueries(n, nums, maxDiff, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')