import os
import sys
from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        res = [i for i in range(n)]
        res.sort(key = lambda x : nums[x])
        transidx = [0] * n
        for i in range(n):
            transidx[res[i]] = i
        nums.sort()
        k = n.bit_length()
        memo = [[0] * k for _ in range(n)]
        curr = 0
        for i in range(n):
            curr = max(curr, i)
            while curr + 1 < n and nums[i] + maxDiff >= nums[curr + 1]:
                curr += 1
            memo[i][0] = curr
        for j in range(1, k):
            for i in range(n):
                memo[i][j] = memo[memo[i][j-1]][j-1]
        ans = []
        for x, y in queries:
            x = transidx[x]
            y = transidx[y]
            if x > y:
                x, y = y, x
            if memo[x][k - 1] < y:
                ans.append(-1)
            else:
                curr = x
                steps = 0
                for j in range(k - 1, -1, -1):
                    if memo[curr][j] < y:
                        curr = memo[curr][j]
                        steps += (1 << j)
                ans.append(steps + 1 if curr < y else 0)
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