import os
import sys
from typing import List

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0] * (n+1) for _ in range(m+1)]
        # print(dp)
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    dp[i+1][j+1] = 1 + min(dp[i][j], dp[i][j+1], dp[i+1][j])
        return sum(sum(num) for num in dp)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            matrix = [i.split(',') for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            matrix = [[int(num) for num in sublist] for sublist in matrix]
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
        results.append(solution.countSquares(matrix))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')