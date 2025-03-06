import os
import sys
from typing import List

class Solution:
    def smallestNumber(self, pattern: str) -> str:
        pattern = 'I' + pattern
        n = len(pattern)
        idx = 0
        ans = []
        while idx < n:
            count = 0
            while idx + 1 < n and pattern[idx + 1] == 'D':
                count += 1
                idx += 1
            base = len(ans) + 1
            while count >= 0:
                ans.append(chr(ord('0') + base + count))
                count -= 1
            idx += 1
        print(ans)
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            pattern = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(pattern)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for pattern in dataset:
        results.append(solution.smallestNumber(pattern))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')