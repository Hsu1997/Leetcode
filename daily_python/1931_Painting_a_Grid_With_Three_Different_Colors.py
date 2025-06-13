import os
import sys
from typing import List

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        t = 3 ** m
        valid = {}
        mod = int(1e9 + 7)
        for color in range(t):
            idx = color
            temp = []
            for c in range(m):
                temp.append(color % 3)
                color //= 3
            v = True
            for c in range(m-1):
                if temp[c] == temp[c+1]:
                    v = False
                    break
            if v:
                valid[idx] = temp
        pair = {}
        for x, x_c in valid.items():
            pair[x] = []
            for y, y_c in valid.items():
                v = True
                for c in range(m):
                    if x_c[c] == y_c[c]:
                        v = False
                        break
                if v:
                    pair[x].append(y)
        dp = [[0] * n for _ in range(t)]
        for i in valid.keys():
            dp[i][0] = 1
        for  j in range(n-1):
            for i in range(t):
                if dp[i][j]:
                    for next in pair[i]:
                        dp[next][j+1] = (dp[next][j+1] + dp[i][j]) % mod
        ans = 0
        for i in range(t):
            ans = (ans + dp[i][n-1]) % mod
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((m, n))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n in dataset:
        results.append(solution.colorTheGrid(m, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')