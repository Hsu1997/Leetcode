import os
import sys
from typing import List

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m = len(str1)
        n = len(str2)
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 if str1[0] == str2[0] else 0
        for col in range(1, n):
            dp[0][col] = dp[0][col-1] or str1[0] == str2[col]
        for row in range(1, m):
            dp[row][0] = dp[row-1][0] or str1[row] == str2[0]
            for col in range(1, n):
                if str1[row] == str2[col]:
                    dp[row][col] = dp[row-1][col-1] + 1
                else:
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1])
        LCS = []
        i = m - 1
        j = n - 1
        while i > 0 and j > 0:
            if dp[i][j] == dp[i-1][j]:
                i -= 1
            elif dp[i][j] == dp[i][j-1]:
                j -= 1
            else:
                LCS.append(str1[i])
                i -= 1
                j -= 1
        if dp[i][j] == 1:
            while i > 0 and dp[i-1][0] == 1:
                i -= 1
            LCS.append(str1[i])
        ans = []
        i = 0
        j = 0
        for cs in LCS[::-1]:
            while str1[i] != cs:
                ans.append(str1[i])
                i += 1
            while str2[j] != cs:
                ans.append(str2[j])
                j += 1
            ans.append(cs)
            i += 1
            j += 1
        while i < m:
            ans.append(str1[i])
            i += 1
        while j < n:
            ans.append(str2[j])
            j += 1
        return "".join(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            str1 = lines[0].split('=')[1].strip()[1:-2]
            str2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((str1, str2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for str1, str2 in dataset:
        results.append(solution.shortestCommonSupersequence(str1, str2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')