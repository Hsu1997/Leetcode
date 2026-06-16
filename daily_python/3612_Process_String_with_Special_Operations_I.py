import os
import sys
from typing import List

class Solution:
    def processStr(self, s: str) -> str:
        ans = []
        for c in s:
            if c == '*':
                if c:
                    ans.pop()
            elif c == '#':
                ans += ans.copy()
            elif c == '%':
                ans = ans[::-1]
            else:
                ans.append(c)
        return "".join(ans)
    
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
        results.append(solution.processStr(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')