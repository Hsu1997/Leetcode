import os
import sys
import heapq
import math
from typing import List

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = [-gift for gift in gifts]
        heapq.heapify(pq)
        for _ in range(k):
            M = -heapq.heappop(pq)
            heapq.heappush(pq, -math.floor(math.sqrt(M)))
        ans = 0
        while pq:
            ans -= pq.pop()
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            gifts = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((gifts, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for gifts, k in dataset:
        results.append(solution.pickGifts(gifts, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')