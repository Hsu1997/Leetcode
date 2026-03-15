import os
import sys
from typing import List
from math import floor

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        maxWorkerTime = max(workerTimes)
        l = 1
        r = floor(maxWorkerTime * mountainHeight * (mountainHeight + 1) / 2)
        ans = r + 1
        while l <= r:
            mid = (l + r) // 2
            cnt = 0
            for w in workerTimes:
                work = mid // w
                k = floor((-1 + (1 + 8 * work) ** 0.5) / 2)
                cnt += k
            if cnt >= mountainHeight:
                ans = min(ans, mid)
                r = mid - 1
            else:
                l = mid + 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mountainHeight = int(lines[0].split('=')[1].strip()[:-1])
            workerTimes = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((mountainHeight, workerTimes))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mountainHeight, workerTimes in dataset:
        results.append(solution.minNumberOfSeconds(mountainHeight, workerTimes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    