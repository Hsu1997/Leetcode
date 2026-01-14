import os
import sys
from typing import List

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 0
        for i in range(1, n):
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]))
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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for points in dataset:
        results.append(solution.minTimeToVisitAllPoints(points))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')