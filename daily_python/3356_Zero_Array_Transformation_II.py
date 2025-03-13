import os
import sys
from typing import List

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        k = 0
        acc = 0
        diff = [0] * (n + 1)
        for idx in range(n):
            while acc + diff[idx] < nums[idx]:
                if k == len(queries):
                    return -1
                start, end, val = queries[k][0], queries[k][1], queries[k][2]
                if end >= idx:
                    diff[max(start, idx)] += val
                    diff[end + 1] -= val
                k += 1
            acc += diff[idx]
        return k

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
        results.append(solution.minZeroArray(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')