import os
import sys
from typing import List

class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        r = len(rectangles)
        cut = 0
        end = 0
        sorted_horizotal = sorted(rectangles, key = lambda x : x[0])
        sorted_vertical = sorted(rectangles, key = lambda x : x[1])
        # cut vertical
        for startx, starty, endx, endy in sorted_horizotal:
            if startx >= end:
                cut += 1
                if cut == 3:
                    return True
            end = max(end, endx)
        cut = 0
        end = 0
        # cut horizontal
        for startx, starty, endx, endy in sorted_vertical:
            if starty >= end:
                cut += 1
                if cut == 3:
                    return True
            end = max(end, endy)
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            rectangles = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, rectangles))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, rectangles in dataset:
        results.append(solution.checkValidCuts(n, rectangles))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')