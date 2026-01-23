import os
import sys
from typing import List

class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        if not hBars or not vBars:
            return 1
        hBars.sort()
        vBars.sort()
        hc, vc = 2, 2
        maxhc = 2
        maxvc = 2
        for i in range(1, len(hBars)):
            if hBars[i] == hBars[i-1] + 1:
                hc += 1
                maxhc = max(maxhc, hc)
            else:
                hc = 2
        for i in range(1, len(vBars)):
            if vBars[i] == vBars[i-1] + 1:
                vc += 1
                maxvc = max(maxvc, vc)
            else:
                vc = 2
        return min(maxhc, maxvc) * min(maxhc, maxvc)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            m = int(lines[1].split('=')[1].strip()[:-1])
            hBars = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            vBars = list(map(int, lines[3].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((n, m, hBars, vBars))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, m, hBars, vBars in dataset:
        results.append(solution.maximizeSquareHoleArea(n, m, hBars, vBars))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
