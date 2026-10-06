import os
import sys
from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []
        def dfs(open, close, s):
            if open == 0 and close == 0:
                ans.append(s)
                return
            if open:
                dfs(open - 1, close, s + '(')
            if close > open:
                dfs(open, close - 1, s + ')')
        dfs(n, n, '')
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.generateParenthesis(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
