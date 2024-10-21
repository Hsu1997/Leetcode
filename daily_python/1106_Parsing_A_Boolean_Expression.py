import os
import sys
from collections import deque

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        q = deque()
        for c in expression:
            if c in ['(', ',']:
                continue
            elif c in ['&', '|', '!', 't', 'f']:
                q.append(c)
            elif c == ')':
                has_t = False
                has_f = False
                while q[-1] not in ['&', '|', '!']:
                    curr = q.pop()
                    if curr == 't':
                        has_t = True
                    if curr == 'f':
                        has_f = True
                op = q.pop()
                if op == '&':
                    q.append('f' if has_f else 't')
                elif op == '|':
                    q.append('t' if has_t else 'f')
                elif op == '!':
                    q.append('t' if has_f else 'f')
        return q[-1] == 't'
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            expression = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(expression)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for expression in dataset:
        results.append(solution.parseBoolExpr(expression))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')