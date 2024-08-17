import os
import sys
from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        row = len(points)
        col = len(points[0])
        pre_dp = points[0]
        dp = [0] * col
        for i in range(1, row):
            temp_max = 0
            for j in range(col):
                temp_max = max(temp_max - 1, pre_dp[j])
                dp[j] = points[i][j] + temp_max
            temp_max = 0
            for j in range(col-1, -1, -1):
                temp_max = max(temp_max - 1, pre_dp[j])
                dp[j] = max(dp[j], points[i][j] + temp_max)
            pre_dp = dp.copy()
        return max(pre_dp)
    
def readDataSet(filename: str)-> None:
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            points = lines[0].split('=')[1][1:-1].replace('{', '[').replace('}',']')
            points = eval(points)
            dataset.append(points)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for points in dataset:
        results.append(solution.maxPoints(points))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')