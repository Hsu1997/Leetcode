import os
import sys
from typing import List

class Solution:
    def dfs(self, s: str, pos: int, prev: int, curr: int, isLimit: bool, isLeading: bool) -> List[int]:
        if pos == len(s):
            return [1, 0]
        if prev != -1 and curr != -1 and not isLimit and not isLeading and self.memoCnt[pos][prev][curr] != -1:
            return [self.memoCnt[pos][prev][curr], self.memoSum[pos][prev][curr]]
        up = ord(s[pos]) - ord('0') if isLimit else 9
        cnt, sum = 0, 0
        for digit in range(up + 1):
            newIsLimit = isLimit and (digit == up)
            newIsLeading = isLeading and (digit == 0)
            newPrev = curr
            newCurr = -1 if newIsLeading else digit
            subCnt, subSum = self.dfs(s, pos + 1, newPrev, newCurr, newIsLimit, newIsLeading)
            cnt += subCnt
            sum +=subSum
            if not isLeading and prev != -1 and curr != -1:
                if prev < curr > digit or prev > curr < digit:
                    sum += subCnt
        if prev != -1 and curr != -1 and not isLimit and not isLeading:
            self.memoCnt[pos][prev][curr] = cnt
            self.memoSum[pos][prev][curr] = sum
        return [cnt, sum]
    
    def solve(self, num) -> int:
        self.memoCnt = [[[-1] * 10 for _ in range(10)] for _ in range(16)]
        self.memoSum = [[[-1] * 10 for _ in range(10)] for _ in range(16)]
        s = str(num)
        _, s = self.dfs(s, 0, -1, -1, 1, 1)
        return s
    
    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.solve(num2) - self.solve(num1 - 1)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num1 = int(lines[0].split('=')[1].strip()[:-1])
            num2 = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((num1, num2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num1, num2 in dataset:
        results.append(solution.totalWaviness(num1, num2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')