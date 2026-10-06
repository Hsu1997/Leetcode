import os
import sys
from typing import List

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        sta = [-1]
        ans = 0
        for i in range(n):
            if s[i] == '(':
                sta.append(i)
            else:
                sta.pop()
                if not sta:
                    sta.append(i)
                else:
                    ans = max(ans, i - sta[-1])
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
        results.append(solution.longestValidParentheses(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')