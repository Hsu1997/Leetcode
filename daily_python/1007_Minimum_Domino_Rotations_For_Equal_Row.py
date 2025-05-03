import os
import sys
from typing import List

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        ans = float('inf')
        for num in range(1, 7):
            valid = True
            t = 0
            b = 0
            for top, bottom in zip(tops, bottoms):
                if top != num and bottom != num:
                    valid = False
                    break
                t += 1 if top == num else 0
                b += 1 if bottom == num else 0
            if valid:
                ans = min(ans, len(tops) - t, len(tops) - b)
        return ans if ans != float('inf') else -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            tops = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            bottoms = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((tops, bottoms))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for tops, bottoms in dataset:
        results.append(solution.minDominoRotations(tops, bottoms))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')