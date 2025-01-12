import os
import sys
from typing import List

class Solution:
    def upper_bound(self, end, begining):
        left = 0
        right = len(begining) - 1
        if begining[left] > end:
            return left
        while(left < right):
            mid = (left + right) // 2
            if begining[mid] > end:
                right = mid
            else:
                left = mid + 1
        return right

    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        ans = 0
        begining = [0] * (n + 1)
        begining[n] = float('INF')
        after_max = [0] * (n + 1)
        for i in range(n-1, -1, -1):
            begining[i] = events[i][0]
            after_max[i] = max(events[i][2], after_max[i+1])
        for i in range(n):
            end = events[i][1]
            idx = self.upper_bound(end, begining)
            if idx < n:
                ans = max(ans, events[i][2] + after_max[idx])
            else:
                ans = max(ans, events[i][2])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            events = [list(map(int, event.split(','))) for event in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(events)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for events in dataset:
        results.append(solution.maxTwoEvents(events))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')