import os
import sys
from typing import List

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total = sum(apple)
        ans = 0
        capacity = sorted(capacity, key = lambda x : -x)
        while ans < len(capacity) and total > 0:
            total -= capacity[ans]
            ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            apple = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            capacity = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((apple, capacity))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for apple, capacity in dataset:
        results.append(solution.minimumBoxes(apple, capacity))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')