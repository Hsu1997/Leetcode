import os
import sys
from typing import List
import heapq

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        next_pos = [-1] * n
        ans = [-1] * n
        lastest = {}
        for i in range(n-1, -1, -1):
            if rains[i] in lastest:
                next_pos[i] = lastest[rains[i]]
            lastest[rains[i]] = i
        full = set()
        pq = []
        for i in range(n):
            if rains[i] == 0:
                if pq:
                    pos, idx = heapq.heappop(pq)
                    ans[i] = idx
                    full.remove(idx)
                else:
                    ans[i] = 1
            else:
                if rains[i] in full:
                    return []
                full.add(rains[i])
                if next_pos[i] != -1:
                    heapq.heappush(pq, (next_pos[i], rains[i]))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            rains = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(rains)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for rains in dataset:
        results.append(solution.avoidFlood(rains))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')