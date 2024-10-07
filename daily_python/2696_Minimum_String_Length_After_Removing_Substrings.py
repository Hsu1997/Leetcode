import os
import sys
from queue import Queue

class Solution:
    def minLength(self, s: str) -> int:
        sta = []
        for c in s:
            if not sta:
                sta.append(c)
            elif c == 'B' and sta[-1] == 'A':
                sta.pop()
            elif c == 'D' and sta[-1] == 'C':
                sta.pop()
            else:
                sta.append(c)
        return len(sta)
    
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
        results.append(solution.minLength(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')