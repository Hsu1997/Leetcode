import os
import sys
from typing import List

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        cnt = s.count('1')
        prev = float('-inf')
        maxTwoInterval = 0
        i, n = 0, len(s)
        while i < n:
            start = i
            while i < n and s[i] == s[start]:
                i += 1
            if s[start] == '0':
                maxTwoInterval = max(maxTwoInterval, prev + (i - start))
                prev = i - start
        return cnt + maxTwoInterval

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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.maxActiveSectionsAfterTrade(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')