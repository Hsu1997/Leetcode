import os
import sys
from math import gcd
from collections import defaultdict

class Solution:
    def countTrapezoids(self, points):
        n = len(points)
        slope_to_intercepts = defaultdict(list)
        mid_to_slopes = defaultdict(list)

        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx = x2 - x1
                dy = y2 - y1
                if dx == 0:
                    slope = (1, 0)
                    bkey = x1
                elif dy == 0:
                    slope = (0, 1)
                    bkey = y1
                else:
                    if dx < 0:
                        dx = -dx
                        dy = -dy
                    g = gcd(abs(dx), abs(dy))
                    dx //= g
                    dy //= g
                    slope = (dy, dx)
                    bkey = dx * y1 - dy * x1
                slope_to_intercepts[slope].append(bkey)
                mid_to_slopes[(x1 + x2, y1 + y2)].append(slope)
        ans = 0
        for intercepts in slope_to_intercepts.values():
            cnt = defaultdict(int)
            for b in intercepts:
                cnt[b] += 1
            acc = 0
            for c in cnt.values():
                ans += acc * c
                acc += c
        for slopes in mid_to_slopes.values():
            cnt = defaultdict(int)
            for s in slopes:
                cnt[s] += 1
            acc = 0
            for c in cnt.values():
                ans -= acc * c
                acc += c
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