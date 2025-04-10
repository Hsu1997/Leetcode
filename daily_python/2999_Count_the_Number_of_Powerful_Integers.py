import os
import sys
from typing import List

class Solution:
    def dfs(self, index: int, limit_low: bool, limit_high: bool, start: str, finish: str, n: int, preLen: int, limit: int, s: str) -> int:
        if index == n:
            return 1
        if not limit_low and not limit_high and self.dp[index] != -1:
            return self.dp[index]
        lo = int(start[index]) if limit_low else 0
        hi = int(finish[index]) if limit_high else 9
        ans = 0
        if index < preLen:
            for digit in range(lo, min(hi, limit) + 1):
                ans += self.dfs(index+1, limit_low and digit == lo, limit_high and digit == hi, start, finish, n, preLen, limit, s)
        else:
            x = int(s[index - preLen])
            if lo <= x <= min(hi, limit):
                ans = self.dfs(index + 1, limit_low and x == lo, limit_high and x == hi, start, finish, n, preLen, limit, s)
        if not limit_low and not limit_high:
            self.dp[index] = ans
        return ans
    
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        start = str(start)
        finish = str(finish)
        start = '0' * (len(finish) - len(start)) + start
        n = len(start)
        preLen = n - len(s)
        self.dp = [-1] * n
        return self.dfs(0, 1, 1, start, finish, n, preLen, limit, s)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            start = int(lines[0].split('=')[1].strip()[:-1])
            finish = int(lines[1].split('=')[1].strip()[:-1])
            limit = int(lines[2].split('=')[1].strip()[:-1])
            s = lines[3].split('=')[1].strip()[1:-2]
            dataset.append((start, finish, limit, s))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for start, finish, limit, s in dataset:
        results.append(solution.numberOfPowerfulInt(start, finish, limit, s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    