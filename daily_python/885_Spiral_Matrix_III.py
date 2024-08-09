import sys
import os
from typing import List

class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        dir = [[0,1],[1,0],[0,-1],[-1,0]]
        ans = []
        direction = 0
        step = 1
        while len(ans) < rows * cols:
            for _ in range(2):
                for _ in range(step):
                    if rStart >= 0 and cStart >= 0 and rStart < rows and cStart < cols:
                        ans.append([rStart, cStart])
                    rStart += dir[direction][0]
                    cStart += dir[direction][1]
                direction = (direction + 1) % 4
            step += 1
        return ans
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            rows = int(lines[0].split('=')[1].strip().strip(';'))
            cols = int(lines[1].split('=')[1].strip().strip(';'))
            rStart = int(lines[2].split('=')[1].strip().strip(';'))
            cStart = int(lines[3].split('=')[1].strip().strip(';'))
            dataset.append((rows, cols, rStart, cStart))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for rows, cols, rStart, cStart in dataset:
        results.append(solution.spiralMatrixIII(rows, cols, rStart, cStart))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')