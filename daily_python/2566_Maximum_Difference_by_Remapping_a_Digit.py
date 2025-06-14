import os
import sys
from typing import List

class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        t = s
        pos = 0
        while pos < len(s) and s[pos] == '9':
            pos += 1
        if pos < len(s):
            s = s.replace(s[pos], '9')
        t = t.replace(t[0], '0')
        return int(s) - int(t)

def readDatSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDatSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.minMaxDifference(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')