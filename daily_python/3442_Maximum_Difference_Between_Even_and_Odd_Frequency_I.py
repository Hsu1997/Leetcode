import os
import sys
from typing import List

class Solution:
    def maxDifference(self, s: str) -> int:
        M = 0
        m = 10 ** 9
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        for c in cnt:
            if c == 0:
                continue
            if c % 2 == 0:
                m = min(m, c)
            else:
                M = max(M, c)
        return M - m

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
        results.append(solution.maxDifference(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')