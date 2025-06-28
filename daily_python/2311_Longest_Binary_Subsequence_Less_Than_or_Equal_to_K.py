import os
import sys
from typing import List

class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans = sum(1 if c == '0' else 0 for c in s)
        curr = 0
        for i in range(len(s)):
            c = s[len(s) - 1 - i]
            if c == '0':
                continue
            else:
                curr += (1 << i)
                if curr > k:
                    break
                ans += 1
        return ans
    
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
        results.append(solution.longestSubsequence(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')