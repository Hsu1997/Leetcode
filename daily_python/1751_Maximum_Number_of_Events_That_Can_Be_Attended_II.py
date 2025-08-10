import os
import sys
from typing import List
import bisect

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        events.sort(key = lambda x : x[0])
        start = [event[0] for event in events]
        next_event = [bisect.bisect_right(start, event[1]) for event in events]
        dp = [[0] * n for _ in range(k)]
        dp[0][n-1] = events[n-1][2]
        for j in range(n-2, -1, -1):
            dp[0][j] = max(events[j][2], dp[0][j+1])
        for i in range(1, k):
            dp[i][n-1] = dp[i-1][n-1]
            for j in range(n-2, -1, -1):
                take = events[j][2] + (dp[i-1][next_event[j]] if next_event[j] < n else 0)
                dp[i][j] = max(dp[i][j+1], take)
        return max([max(r) for r in dp])

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            events = [list(map(int, event.split(','))) for event in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((events, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for events, k in dataset:
        results.append(solution.maxValue(events, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')