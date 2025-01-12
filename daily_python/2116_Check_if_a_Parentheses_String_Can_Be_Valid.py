import os
import sys
from typing import List

class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n % 2 == 1:
            return False
        open = sum(s[i] == '(' and locked[i] == '1' for i in range(n))
        close = sum(s[i] == ')' and locked[i] == '1' for i in range(n))
        if open > n/2 or close > n/2:
            return False
        change = n/2 - open
        acc = 0
        for i in range(n):
            if locked[i] == '1':
                acc = acc + (1 if s[i] == '(' else -1)
            else:
                if change > 0:
                    change -= 1
                    acc += 1
                else:
                    acc -= 1
            if acc < 0:
                return False
        return acc == 0

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            locked = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s, locked))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, locked in dataset:
        results.append(solution.canBeValid(s, locked))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')