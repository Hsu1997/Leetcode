import os
import sys
from typing import List

class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        area = 0
        diagonal = 0
        for rectangle in dimensions:
            l = rectangle[0]
            w = rectangle[1]
            if l * l + w * w > diagonal:
                diagonal = l * l + w * w
                area = l * w
            elif l * l + w * w == diagonal:
                area = max(area, l * w)
        return area

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            dimensions = [list(map(int, d.split(','))) for d in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(dimensions)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for dimensions in dataset:
        results.append(solution.areaOfMaxDiagonal(dimensions))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    