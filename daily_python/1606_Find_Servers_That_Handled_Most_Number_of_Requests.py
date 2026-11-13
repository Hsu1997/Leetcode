import os
import sys
from typing import List
import heapq

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        n = len(arrival)
        cnt = [0] * k
        ans = []
        free = [i for i in range(k)]
        busy = []
        for i, t in enumerate(arrival):
            while busy and busy[0][0] <= t:
                curr = busy[0][1]
                heapq.heappop(busy)
                heapq.heappush(free, i + (curr - (i % k)) % k)
            if not free:
                continue
            curr = heapq.heappop(free) % k
            cnt[curr] += 1
            heapq.heappush(busy, ((t + load[i]), curr))
        m = max(cnt)
        for i in range(k):
            if cnt[i] == m:
                ans.append(i)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            k = int(lines[0].split('=')[1].strip()[:-1])
            arrival = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            load = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((k, arrival, load))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for k, arrival, load in dataset:
        results.append(solution.busiestServers(k, arrival, load))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')