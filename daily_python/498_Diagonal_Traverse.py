import os
import sys
from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        ans = []
        for round in range(m + n - 1):
            temp = []
            if round < n:
                i = 0
                j = round
            else:
                i = round - n + 1
                j = n - 1
            while i < m and j >= 0:
                temp.append(mat[i][j])
                i += 1
                j -= 1
            if round % 2 == 0:
                ans.extend(temp[::-1])
            else:
                ans.extend(temp)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mat = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(mat)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mat in dataset:
        results.append(solution.findDiagonalOrder(mat))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')