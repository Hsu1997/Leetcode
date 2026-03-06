import os
import sys
from typing import List

class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0
        for start in range(n):
            maxcnt = 0
            maxAppearTimes = 0
            cnt = [0] * 26
            for end in range(start, n):
                c = ord(s[end]) - ord('a')
                cnt[c] += 1
                if cnt[c] > maxcnt:
                    maxcnt = cnt[c]
                    maxAppearTimes = 1
                elif cnt[c] == maxcnt:
                    maxAppearTimes += 1
                else:
                    continue
                if end - start + 1 == maxcnt * maxAppearTimes:
                    ans = max(ans, end - start + 1)
        return ans

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
        results.append(solution.longestBalanced(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')