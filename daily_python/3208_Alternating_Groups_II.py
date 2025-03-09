import os
import sys
from typing import List
from collections import deque

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        ans = 0
        alternatingElementsCount = 1
        last_color = colors[0]
        for i in range(1, n + k - 1):
            if colors[i % n] == last_color:
                alternatingElementsCount = 1
                last_color = colors[i % n]
                continue
            alternatingElementsCount += 1
            if alternatingElementsCount >= k:
                ans += 1
            last_color = colors[i % n]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            colors = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((colors, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for colors, k in dataset:
        results.append(solution.numberOfAlternatingGroups(colors, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
