import os
import sys
from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        startTime = startTime + [eventTime]
        endTime = [0] + endTime
        n = len(startTime)
        ans = 0
        acc = 0
        for i in range(n):
            acc += startTime[i] - endTime[i]
            if i - k - 1 >= 0:
                acc -= startTime[i - k - 1] - endTime[i - k - 1]
            ans = max(ans, acc)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            eventTime = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            startTime = list(map(int,lines[2].split('=')[1].strip()[1:-2].split(',')))
            endTime = list(map(int,lines[3].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((eventTime, k, startTime, endTime))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for eventTime, k, startTime, endTime in dataset:
        results.append(solution.maxFreeTime(eventTime, k, startTime, endTime))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')