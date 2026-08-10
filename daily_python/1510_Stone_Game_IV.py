import sys
import os
from typing import List

class Solution:
    MAX = 100000
    dp = [False] * (MAX + 1)
    square = []
    k = 1
    while k * k <= MAX:
        square.append(k * k)
        k += 1
    for i in range(MAX + 1):
        if dp[i]:
            continue
        for s in square:
            if i + s > MAX:
                break
            dp[i + s] = True
    def winnerSquareGame(self, n: int) -> bool:
        return self.dp[n]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[0])
            dataset.append(n)
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
    for n in dataset:
        results.append(solution.winnerSquareGame(n))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')