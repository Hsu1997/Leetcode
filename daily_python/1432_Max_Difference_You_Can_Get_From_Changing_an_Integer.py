import os
import sys
from typing import List

class Solution:
    def maxDiff(self, num: int) -> int:
        s = str(num)
        t = str(num)
        for d in s:
            if d != '9':
                s = s.replace(d, '9')
                break
        for i, d in enumerate(t):
            if i == 0 and d != '1':
                t = t.replace(d, '1')
                break
            elif d != '0' and d != '1':
                t = t.replace(d, '0')
                break
        return int(s) - int(t)
    
def readDataSet(filename):
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
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.maxDiff(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')