import os
import sys
from typing import List

class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        MOD = 10 ** 9 + 7
        dp = [[[-1, 0] for _ in range(n)] for _ in range(n)]
        dp[0][0] = [0, 1]
        for i in range(n):
            for j in range(n):
                if (i == 0 and j == 0) or board[i][j] == 'X':
                    continue
                curr = 0 if i == n - 1 and j == n - 1 else ord(board[i][j]) - ord('0')
                v = max(-1, dp[i-1][j][0] if i > 0 else -1, dp[i][j-1][0] if j > 0 else -1, dp[i-1][j-1][0] if i > 0 and j > 0 else -1)
                if v > -1:
                    dp[i][j][0] = v + curr
                    dp[i][j][1] += (dp[i-1][j][1] if i > 0 and dp[i-1][j][0] == v else 0) + (dp[i][j-1][1] if j > 0 and dp[i][j-1][0] == v else 0) + (dp[i-1][j-1][1] if i > 0 and j > 0 and dp[i-1][j-1][0] == v else 0)
                    dp[i][j][1] %= MOD
        return dp[n-1][n-1] if dp[n-1][n-1][0] != -1 else [0, 0]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            board = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            dataset.append(board)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for board in dataset:
        results.append(solution.pathsWithMaxScore(board))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')