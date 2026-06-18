import os
import sys
from typing import List

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = (hour % 12) + (minutes / 60)
        m = minutes / 5
        d = abs(h - m)
        d = min(d, 12 - d)
        return d * 30

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            hour = int(lines[0].split('=')[1].strip()[:-1])
            minutes = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((hour, minutes))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for hour, minutes in dataset:
        results.append(solution.angleClock(hour, minutes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')