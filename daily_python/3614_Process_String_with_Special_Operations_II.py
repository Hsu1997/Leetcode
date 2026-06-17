import os
import sys
from typing import List

class Solution:
    def processStr(self, s: str, k: int) -> str:
        l = 0
        for c in s:
            if c == '*':
                if l > 0:
                    l -= 1
            elif c == '#':
                l *= 2
            elif c == '%':
                continue
            else:
                l += 1
        if k >= l:
            return '.'
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c == '*':
                l += 1
            elif c == '#':
                l //= 2
                if k >= l:
                    k -= l
            elif c == '%':
                k = l - 1 - k
            else:
                if k == l - 1:
                    return c
                l -= 1
        return '-'
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.processStr(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')