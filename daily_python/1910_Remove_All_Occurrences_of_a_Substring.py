import os
import sys
from typing import List

class Solution:
    def computeLPS(self, pattern):
        m = len(pattern)
        lps = [0] * m
        l = 0
        for i in range(1, m):
            while l > 0 and pattern[i] != pattern[l]:
                l = lps[l - 1]
            l += (pattern[i] == pattern[l])
            lps[i] = l
        return lps
    
    def removeOccurrences(self, s: str, part: str) -> str:
        n = len(s)
        m = len(part)
        lps = self.computeLPS(part)
        stack = []
        l = 0
        for i in range(n):
            while l > 0 and s[i] != part[l]:
                l = lps[l - 1]
            l += (s[i] == part[l])
            stack.append([i, l])
            if l == m:
                for _ in range(m):
                    stack.pop()
                l = 0 if not stack else stack[-1][1]
        return "".join(s[idx] for idx, _ in stack)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            part = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s, part))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, part in dataset:
        results.append(solution.removeOccurrences(s, part))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')