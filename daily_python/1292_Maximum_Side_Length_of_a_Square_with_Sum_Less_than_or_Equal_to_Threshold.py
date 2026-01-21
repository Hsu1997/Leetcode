import os
import sys
from typing import List

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        P = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + mat[i][j]

        def getRec(x1: int, x2: int, y1: int, y2: int) -> int:
            return P[x2+1][y2+1] - P[x1][y2+1] - P[x2+1][y1] + P[x1][y1]
        
        ans = 0
        for i in range(m):
            for j in range(n):
                for c in range(ans + 1, min(m, n) + 1):
                    if i + c - 1 < m and j + c - 1 < n and getRec(i, i + c - 1, j, j + c - 1) <= threshold:
                        ans = c
                    else:
                        break
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mat = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            threshold = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((mat, threshold))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mat, threshold in dataset:
        results.append(solution.maxSideLength(mat, threshold))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')