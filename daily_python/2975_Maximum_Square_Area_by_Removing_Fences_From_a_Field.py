import os
import sys
from typing import List

class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        hFences = sorted([1, m] + hFences)
        vFences = sorted([1, n] + vFences)
        h = { hFences[i] - hFences[j] for i in range(len(hFences)) for j in range(i) }
        v = { vFences[i] - vFences[j] for i in range(len(vFences)) for j in range(i) }
        res = 0
        for d in h:
            if d in v:
                res = max(res, d)
        return -1 if res == 0 else res * res % (10 ** 9 + 7)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            hFences = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            vFences = list(map(int, lines[3].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((m, n, hFences, vFences))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n, hFences, vFences in dataset:
        results.append(solution.maximizeSquareArea(m, n, hFences, vFences))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
