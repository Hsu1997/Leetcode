import os
import sys
from typing import List

class Solution:
    def search(self, monotonic, val):
        left = 0
        right = len(monotonic) - 1
        ans = -1
        while left <= right:
            mid = (left + right) // 2
            if monotonic[mid][0] > val:
                ans = max(ans, mid)
                left = mid + 1
            else:
                right = mid - 1
        return ans
    
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        q = len(queries)
        monotonic = []
        ans = [-1] * q
        Q = [[] for _ in range(n)]
        for i in range(q):
            a = queries[i][0]
            b = queries[i][1]
            if a > b:
                a, b = b, a
            if a == b or heights[a] < heights[b]:
                ans[i] = b
                continue
            Q[b].append((heights[a], i))
        for i in range(n-1, -1, -1):
            for val, idx in Q[i]:
                if monotonic and monotonic[0][0] > val:
                    ans[idx] = monotonic[self.search(monotonic, val)][1]
            while monotonic and monotonic[-1][0] <= heights[i]:
                monotonic.pop()
            monotonic.append((heights[i], i))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            heights = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((heights, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for heights, queries in dataset:
        results.append(solution.leftmostBuildingQueries(heights, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
