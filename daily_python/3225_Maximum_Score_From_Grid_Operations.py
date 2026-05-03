import os
import sys
from typing import List

class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 1:
            return 0

        col_sum = [[0] * (n + 1) for _ in range(n)]
        for c in range(n):
            for r in range(1, n + 1):
                col_sum[c][r] = col_sum[c][r - 1] + grid[r - 1][c]

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(n)]
        prev_suffix_max = [[0] * (n + 1) for _ in range(n + 1)]
        prev_max = [[0] * (n + 1) for _ in range(n + 1)]

        for i in range(1, n):
            for curr_h in range(n + 1):
                for prev_h in range(n + 1):
                    if curr_h <= prev_h:
                        extra_earn = col_sum[i][prev_h] - col_sum[i][curr_h]
                        dp[i][curr_h][prev_h] = max(dp[i][curr_h][prev_h], prev_suffix_max[prev_h][0] + extra_earn)
                    else:
                        extra_earn = col_sum[i - 1][curr_h] - col_sum[i - 1][prev_h]
                        dp[i][curr_h][prev_h] = max(dp[i][curr_h][prev_h], prev_suffix_max[prev_h][curr_h], prev_max[prev_h][curr_h] + extra_earn)

            for curr_h in range(n + 1):
                prev_max[curr_h][0] = dp[i][curr_h][0]
                for prev_h in range(1, n + 1):
                    penalty = col_sum[i][prev_h] - col_sum[i][curr_h] if prev_h > curr_h else 0
                    prev_max[curr_h][prev_h] = max(prev_max[curr_h][prev_h - 1], dp[i][curr_h][prev_h] - penalty)

                prev_suffix_max[curr_h][n] = dp[i][curr_h][n]
                for prev_h in range(n - 1, -1, -1):
                    prev_suffix_max[curr_h][prev_h] = max(prev_suffix_max[curr_h][prev_h + 1], dp[i][curr_h][prev_h])

        ans = 0
        for prev_h in range(n + 1):
            ans = max(ans, dp[n - 1][0][prev_h], dp[n - 1][n][prev_h])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename) as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            grid = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(grid)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.maximumScore(grid))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')