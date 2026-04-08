import os
import sys
from typing import List

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = int(10 ** 9 + 7)
        for l, r, k, v in queries:
            for idx in range(l, r + 1, k):
                nums[idx] = (nums[idx] * v) % mod
        ans = 0
        for i in nums:
            ans ^= i
        return ans

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
        results.append(solution.xorAfterQueries(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')