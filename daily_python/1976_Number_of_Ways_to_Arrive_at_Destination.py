import os
import sys
from typing import List

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        mod = 1e9+7
        dp = [[[0] * 2 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i == j:
                    dp[i][j][0] = 0
                    dp[i][j][1] = 1
                else:
                    dp[i][j][0] = 1e12
                    dp[i][j][1] = 0
        for road in roads:
            start = road[0]
            end = road[1]
            w = road[2]
            dp[start][end][0] = w
            dp[end][start][0] = w
            dp[start][end][1] = 1
            dp[end][start][1] = 1
        
        for mid in range(n):
            for i in range(n):
                for j in range(n):
                    if i == mid or j == mid:
                        continue
                    if dp[i][mid][0] + dp[mid][j][0] < dp[i][j][0]:
                        dp[i][j][0] = dp[i][mid][0] + dp[mid][j][0]
                        dp[i][j][1] = (dp[i][mid][1] * dp[mid][j][1]) % mod
                    elif dp[i][mid][0] + dp[mid][j][0] == dp[i][j][0]:
                        dp[i][j][1] = (dp[i][j][1] + dp[i][mid][1] * dp[mid][j][1]) % mod
                    else:
                        continue
        return int(dp[0][n-1][1])
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            roads = [list(map(int, road.split(','))) for road in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, roads))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, roads in dataset:
        results.append(solution.countPaths(n, roads))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')