import os
import sys
import heapq
from typing import List
from collections import Counter

class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        count = Counter(ranks)
        pq = [(rank, rank, 1, count[rank]) for rank in count]
        heapq.heapify(pq)
        time = 0
        while cars > 0:
            time, rank, n, c = heapq.heappop(pq)
            n += 1
            cars -= c
            heapq.heappush(pq, (rank * n * n, rank, n, c))
        return time
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            ranks = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            cars = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((ranks, cars))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for ranks, cars in dataset:
        results.append(solution.repairCars(ranks, cars))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')