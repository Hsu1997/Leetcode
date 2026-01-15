import os
import sys
from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0
        dp = [0] * n
        for i in range(m):
            temp = [0] * n
            st = []
            for j in range(n + 1):
                if j == n:
                    currH = 0
                else:
                    currH = dp[j] + 1 if matrix[i][j] == '1' else 0
                    temp[j] = currH
                while st and temp[st[-1]] >= currH:
                    h = temp[st.pop()]
                    leftSmaller = st[-1] if st else -1
                    ans = max(ans, h * (j - leftSmaller - 1))
                st.append(j)
            dp = temp
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            matrix = [list(map(str, row.split("','"))) for row in lines[0].split('=')[1].strip()[3:-4].split("'},{'")]
            dataset.append(matrix)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for matrix in dataset:
        results.append(solution.maximalRectangle(matrix))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
