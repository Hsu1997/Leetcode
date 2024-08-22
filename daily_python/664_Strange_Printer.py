import os
import sys

class Solution:
    def strangePrinter(self, s: str) -> int:
        _s = s[0]
        for i in range(1, len(s)):
            if s[i] != s[i-1]:
                _s += s[i]
        s = _s
        n = len(s)
        dp = [[n for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 0
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                # start = i if s[i] != s[j] else i + 1
                start = i + 1 if s[i] == s[j] else i
                for mid in range(start, j):
                    dp[i][j] = min(dp[i][j], 1 + dp[start][mid] + dp[mid + 1][j])
        return 1 + dp[0][n-1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.strangePrinter(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')