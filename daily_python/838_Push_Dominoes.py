import os
import sys
from typing import List

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        symbols = [(i, x) for i, x in enumerate(dominoes) if x != '.']
        symbols = [(-1,'L')] + symbols + [(len(dominoes), 'R')]
        # print(symbols)
        ans = list(dominoes)
        for (i, x), (j, y) in zip(symbols, symbols[1:]):
            # print((i, x) , (j, y))
            if x == y:
                for k in range(i+1, j):
                    ans[k] = x
            elif x == 'R':
                for k in range(i+1, (i + j + 1) // 2):
                    ans[k] = 'R'
                    ans[j - (k - i)] = 'L'
                if (j - i) % 2 == 0:
                    ans[i + (j - i) // 2] = '.'
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            dominoes = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(dominoes)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for dominoes in dataset:
        results.append(solution.pushDominoes(dominoes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')