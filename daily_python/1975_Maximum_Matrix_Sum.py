import os
import sys
from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        ans = 0
        negative = 0
        m = float('INF')
        for lines in matrix:
            for num in lines:
                if num <= 0:
                    negative += 1
                ans += abs(num)
                m = min(m, abs(num))
        if negative % 2:
            return ans - 2 * m
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            matrix = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.maxMatrixSum(matrix))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')