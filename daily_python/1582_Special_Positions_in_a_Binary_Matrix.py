import os
import sys
from typing import List

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rowsum = [sum(r) for r in mat]
        colsum = [sum(c) for c in zip(*mat)]
        ans = 0
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 1 and rowsum[r] == 1 and colsum[c] == 1:
                    ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mat = [list(map(int, r.split(','))) for r in lines[0].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.numSpecial(mat))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')