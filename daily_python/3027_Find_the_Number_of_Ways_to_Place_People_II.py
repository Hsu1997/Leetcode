import sys
import os
from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key = lambda a : (a[0], -a[1]))
        ans = 0
        n = len(points)
        for i in range(n):
            highest = -1e9-1
            for j in range(i + 1, n):
                if points[j][1] > points[i][1]:
                    continue
                if points[j][1] > highest:
                    highest = points[j][1]
                    ans += 1
                    if highest == points[i][1]:
                        break
                else:
                    continue
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
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    results = []
    solution = Solution()
    dataset = readDataSet(filename)
    for points in dataset:
        results.append(solution.numberOfPairs(points))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')