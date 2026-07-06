import os
import sys
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x : (x[0], -x[1]))
        curr = 0
        d = 0
        for s, e in intervals:
            if e <= curr:
                d += 1
            curr = max(curr, e)
        return len(intervals) - d

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            intervals = [list(map(int, interval.split(','))) for interval in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(intervals)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for intervals in dataset:
        results.append(solution.removeCoveredIntervals(intervals))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')