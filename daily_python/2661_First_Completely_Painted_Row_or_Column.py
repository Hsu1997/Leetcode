import os
import sys
from typing import List

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        pos = [0] * (m * n + 1)
        for i in range(m):
            for j in range(n):
                pos[mat[i][j]] = (i,j)
        row = [0] * m
        col = [0] * n
        for i in range(m * n):
            r = pos[arr[i]][0]
            c = pos[arr[i]][1]
            row[r] += 1
            col[c] += 1
            if row[r] == n or col[c] == m:
                return i
        return m * n
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            mat = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((arr, mat))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, mat in dataset:
        results.append(solution.firstCompleteIndex(arr, mat))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')