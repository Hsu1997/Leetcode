import os
import sys
from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        times = []
        for time in timePoints:
            times.append(int(time[0:2]) * 60 + int(time[3:]))
        times.sort()
        ans = times[0] + 60 * 24 - times[-1]
        for i in range(1, len(times)):
            ans = min(ans, times[i] - times[i-1])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            timePoints = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            dataset.append(timePoints)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for timePoints in dataset:
        results.append(solution.findMinDifference(timePoints))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')