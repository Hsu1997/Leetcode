import os
import sys
from typing import List

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        prev = []
        ans = 0
        for r in range(m):
            curr = []
            visited = [False] * n
            for h, j in prev:
                if matrix[r][j] != 0:
                    curr.append((h+1, j))
                visited[j] = True
            for j in range(n):
                if not visited[j] and matrix[r][j] == 1:
                    curr.append((1, j))
            for l in range(len(curr)):
                ans = max(ans, (l + 1) * curr[l][0])
            prev = curr
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            matrix = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(matrix)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for matrix in dataset:
        results.append(solution.largestSubmatrix(matrix))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')