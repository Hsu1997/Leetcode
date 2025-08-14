import os
import sys
from typing import List

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans = -1
        prev = '#'
        cnt = 0
        for c in num:
            if c != prev:
                prev = c
                cnt = 0
            cnt += 1
            if cnt == 3:
                ans = max(ans, ord(prev) - ord('0'))
        return str(ans) * 3 if ans != -1 else ""

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.largestGoodInteger(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')