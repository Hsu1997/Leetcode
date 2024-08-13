import sys
import os
from typing import List
import heapq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.pq = nums
        self.n = k
        heapq.heapify(self.pq)
        while len(self.pq) > self.n:
            heapq.heappop(self.pq)

    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)
        if len(self.pq) > self.n:
            heapq.heappop(self.pq)
        return self.pq[0]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            k = int(lines[0].split('=')[1].strip()[0])
            nums = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            process = []
            for i in range(2, len(lines)):
                process.append(int(lines[i]))
            dataset.append((k, nums, process))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for k, nums, process in dataset:
        result = []
        solution = KthLargest(k, nums)
        for added in process:
            result.append(solution.add(added))
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)