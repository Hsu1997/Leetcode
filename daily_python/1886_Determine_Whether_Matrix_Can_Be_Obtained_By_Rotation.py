import os
import sys
from typing import List

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)
        for r in range(4):
            for i in range(n // 2):
                for j in range((n + 1) // 2):
                    (mat[i][j], mat[n-1-j][i], mat[n-1-i][n-1-j], mat[j][n-1-i]) = (mat[n-1-j][i], mat[n-1-i][n-1-j], mat[j][n-1-i], mat[i][j])
            if mat == target:
                return True
        return False

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mat = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            target = [list(map(int, row.split(','))) for row in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((mat, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mat, target in dataset:
        results.append(solution.findRotation(mat, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')