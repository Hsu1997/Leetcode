import os
import sys
from typing import List

class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                w = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
                h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
                ans = max(ans, min(w, h))
        return ans * ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            bottomLeft = [list(map(int, p.split(','))) for p in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            topRight = [list(map(int, p.split(','))) for p in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((bottomLeft, topRight))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for bottomLeft, topRight in dataset:
        results.append(solution.largestSquareArea(bottomLeft, topRight))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')