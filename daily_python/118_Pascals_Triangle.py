import sys
import os
from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for row in range(1, numRows):
            temp = [1] * (row + 1)
            for j in range(1, row):
                temp[j] = ans[-1][j-1] + ans[-1][j]
            ans.append(temp)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            numRows = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(numRows)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for numRows in dataset:
        results.append(solution.generate(numRows))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')