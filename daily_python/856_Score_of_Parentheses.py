import sys
import os
from typing import List

class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        pow = 0
        ans = 0
        for i in range(len(s)):
            if s[i] == '(':
                pow += 1
            else:
                pow -= 1
                if i > 0 and s[i-1] == '(':
                    ans += 1 << pow
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
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.scoreOfParentheses(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')