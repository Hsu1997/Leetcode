import os
import sys
from typing import List
from bisect import bisect_left

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        n = len(points)
        p = []
        for x, y in points:
            if x == 0:
                p.append(y)
            elif y == side:
                p.append(side + x)
            elif x == side:
                p.append(3 * side - y)
            else:
                p.append(4 * side - x)
        p.sort()

        def check(d):
            for start in p:
                cnt = 1
                curr = start
                limit = start + side * 4 - d
                while cnt < k:
                    next = bisect_left(p, curr + d)
                    if next == n or p[next] > limit:
                        break
                    cnt += 1
                    curr = p[next]
                if cnt == k:
                    return True
            return False
        
        left = 1
        right = side
        ans = 0
        while left <= right:
            mid = left + (right - left) // 2
            if check(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            side = int(lines[0].split('=')[1].strip()[:-1])
            points = [list(map(int, point.split(','))) for point in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((side, points, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for side, points, k in dataset:
        results.append(solution.maxDistance(side, points, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')