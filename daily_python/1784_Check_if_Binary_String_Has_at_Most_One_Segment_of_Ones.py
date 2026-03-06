import os
import sys
from typing import List

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        n = len(s)
        ptr = 0
        while ptr < n and s[ptr] == '1':
            ptr += 1
        while ptr < n:
            if s[ptr] == '1':
                return False
            ptr += 1
        return True
    
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
        results.append(solution.checkOnesSegment(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')