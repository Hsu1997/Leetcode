import os
import sys
from typing import List
from collections import defaultdict, deque

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        n = len(s)
        m = len(spaces)
        space_idx = 0
        ans = []
        for i in range(n):
            if space_idx < m and i == spaces[space_idx]:
                ans.append(' ')
                space_idx += 1
            ans.append(s[i])
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            spaces = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((s, spaces))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, spaces in dataset:
        results.append(solution.addSpaces(s, spaces))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')