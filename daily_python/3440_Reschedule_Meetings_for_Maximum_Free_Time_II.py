import os
import sys
from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        ans = 0

        left_empty = 0
        for i in range(n):
            left = (0 if i == 0 else endTime[i-1])
            right = (eventTime if i == n - 1 else startTime[i+1])
            if (endTime[i] - startTime[i]) <= left_empty:
                ans = max(ans, right - left)
            left_empty = max(left_empty, startTime[i] - left)
            ans = max(ans, right - left - (endTime[i] - startTime[i]))

        right_empty = 0
        for i in range(n-1, -1, -1):
            left = (0 if i == 0 else endTime[i-1])
            right = (eventTime if i == n - 1 else startTime[i+1])
            if (endTime[i] - startTime[i]) <= right_empty:
                ans = max(ans, right - left)
            right_empty = max(right_empty, right - endTime[i])
            ans = max(ans, right - left - (endTime[i] - startTime[i]))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            eventTime = int(lines[0].split('=')[1].strip()[:-1])
            startTime = list(map(int,lines[1].split('=')[1].strip()[1:-2].split(',')))
            endTime = list(map(int,lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((eventTime, startTime, endTime))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for eventTime, startTime, endTime in dataset:
        results.append(solution.maxFreeTime(eventTime, startTime, endTime))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')