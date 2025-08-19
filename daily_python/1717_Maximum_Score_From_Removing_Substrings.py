import os
import sys
from typing import List

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        acnt, bcnt, ans = 0, 0, 0
        if x >= y:
            for c in s:
                if c == 'a':
                    acnt += 1
                elif c == 'b':
                    if acnt:
                        ans += x
                        acnt -= 1
                    else:
                        bcnt += 1
                else:
                    ans += min(acnt, bcnt) * y
                    acnt, bcnt = 0, 0
        else:
            for c in s[::-1]:
                if c == 'a':
                    acnt += 1
                elif c == 'b':
                    if acnt:
                        ans += y
                        acnt -= 1
                    else:
                        bcnt += 1
                else:
                    ans += min(acnt, bcnt) * x
                    acnt, bcnt = 0, 0
        ans += min(acnt, bcnt) * min(x, y)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            x = int(lines[1].split('=')[1].strip()[:-1])
            y = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((s, x, y))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, x, y in dataset:
        results.append(solution.maximumGain(s, x, y))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')