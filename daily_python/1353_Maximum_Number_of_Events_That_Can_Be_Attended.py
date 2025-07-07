import os
import sys
from typing import List
import heapq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        n = len(events)
        idx = 0
        pq = []
        t = events[0][0]
        ans = 0
        while idx < n or pq:
            while idx < n and events[idx][0] <= t:
                heapq.heappush(pq, events[idx][1])
                idx += 1
            while pq and pq[0] < t:
                heapq.heappop(pq)
            if pq:
                heapq.heappop(pq)
                ans += 1
            t += 1
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
        results.append(solution.maxEvents(events))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')