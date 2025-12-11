import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        cnt = defaultdict(int)
        mod = 10**9+7
        ans, acc = 0, 0
        for point in points:
            cnt[point[1]] += 1
        for c in cnt.values():
            curr = c * (c - 1) // 2 % mod
            ans = (ans + curr * acc % mod) % mod
            acc = (acc + curr) % mod
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            points = [list(map(int, point.split(','))) for point in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(points)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for points in dataset:
        results.append(solution.countTrapezoids(points))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')