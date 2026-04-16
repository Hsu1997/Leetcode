import os
import sys
from typing import List

class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        q = len(queries)
        dis = [n] * n
        m = {}
        for i in range(n):
            m[nums[i]] = -n + i
        for i in range(n):
            dis[i] = i - m[nums[i]]
            m[nums[i]] = i
        for i in range(n - 1, -1, -1):
            m[nums[i]] = n + i
        for i in range(n - 1, -1, -1):
            dis[i] = min(dis[i], m[nums[i]] - i)
            m[nums[i]] = i
        for i in range(n):
            if dis[i] == n:
                dis[i] = -1
        ans = [dis[q] for q in queries]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
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
        results.append(solution.solveQueries(nums, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')