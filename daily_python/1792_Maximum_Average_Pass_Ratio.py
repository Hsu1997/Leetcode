import os
import sys
import heapq
from typing import List

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        maxheap = []
        def delta(passed, total):
            return (passed+1) / (total+1) - passed / total
        for passed, total in classes:
            maxheap.append((-delta(passed, total), passed, total))
        heapq.heapify(maxheap)
        for _ in range(extraStudents):
            d, passed, total = heapq.heappop(maxheap)
            heapq.heappush(maxheap, (-delta(passed+1, total+1), passed+1, total+1))
        ans = 0
        for _, passed, total in maxheap:
            ans += (passed / total)
        return ans / len(classes)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            classes = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            extraStudents = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((classes, extraStudents))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for classes, extraStudents in dataset:
        results.append(solution.maxAverageRatio(classes, extraStudents))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    