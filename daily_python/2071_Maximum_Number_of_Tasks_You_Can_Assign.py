import os
import sys
from typing import List
from sortedcontainers import SortedList

class Solution:
    def valid(self, tasks, workers, pills, strength, k) -> bool:
        s = SortedList(workers[:k])
        for t in tasks[:k][::-1]:
            if s[-1] >= t:
                s.pop()
            else:
                if pills == 0:
                    return False
                pills -= 1
                w = s.bisect_left(t - strength)
                if w == len(s):
                    return False
                s.pop(w)
        return True
    
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks = sorted(tasks)
        workers = sorted(workers, reverse = True)
        left = 0
        right = min(len(tasks), len(workers))
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if self.valid(tasks, workers, pills, strength, mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            tasks = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            workers = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            pills = int(lines[2].split('=')[1].strip()[:-1])
            strength = int(lines[3].split('=')[1].strip()[:-1])
            dataset.append((tasks, workers, pills, strength))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for tasks, workers, pills, strength in dataset:
        results.append(solution.maxTaskAssign(tasks, workers, pills, strength))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')