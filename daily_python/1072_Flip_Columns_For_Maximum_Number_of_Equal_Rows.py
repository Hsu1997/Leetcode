import os
import sys
from typing import List

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        freq = {}
        for row in matrix:
            curr = "".join("T" if num == row[0] else "F" for num in row)
            freq[curr] = freq.get(curr, 0) + 1
        return max(freq.values())
    
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
        results.append(solution.maxEqualRowsAfterFlips(matrix))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')