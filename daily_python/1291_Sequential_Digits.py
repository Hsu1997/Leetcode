import os
import sys
from typing import List, Optional

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        s = '123456789'
        l = len(str(low))
        h = len(str(high))
        ans = []
        for totalLen in range(l, h + 1):
            for start in range(10 - totalLen):
                curr = int(s[start : start + totalLen])
                if low <= curr <= high:
                    ans.append(curr)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            low = int(lines[0].split('=')[1].strip()[:-1])
            high = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((low, high))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for low, high in dataset:
        results.append(solution.sequentialDigits(low, high))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')