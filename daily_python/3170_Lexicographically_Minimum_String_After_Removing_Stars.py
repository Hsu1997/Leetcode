import os
import sys
from typing import List

class Solution:
    def clearStars(self, s: str) -> str:
        s = list(s)
        n = len(s)
        record = [[] for _ in range(26)]
        for i in range(n):
            if s[i] != '*':
                record[ord(s[i]) - ord('a')].append(i)
            else:
                for c in range(26):
                    if record[c]:
                        s[record[c].pop()] = '*'
                        break
        ans = []
        for c in s:
            if c != '*':
                ans.append(c)
        return "".join(c for c in s if c != '*')

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
        results.append(solution.clearStars(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')