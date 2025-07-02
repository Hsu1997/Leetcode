import os
import sys
from typing import List

class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        horizontal = 0
        vertical = 0
        ans = 0
        for i, c in enumerate(s):
            if c == 'N':
                vertical += 1
            elif c == 'S':
                vertical -= 1
            elif c == 'W':
                horizontal -= 1
            else:
                horizontal += 1
            ans = max(ans, min(abs(horizontal) + abs(vertical) + 2 * k, i + 1))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.maxDistance(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')