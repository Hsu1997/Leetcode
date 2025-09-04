import os
import sys
from typing import List, Tuple

class Solution:
    def dp(self, n: int, f: int, s: int) -> Tuple[int, int]:
        if self.E[n][f][s] != 0:
            return (self.E[n][f][s], self.L[n][f][s])
        if f + s == n + 1:
            return (1, 1)
        if f + s > n + 1:
            e, l = self.dp(n, n + 1 - s, n + 1 - f)
            self.E[n][f][s] = e
            self.L[n][f][s] = l
            return (e, l)
        half = (n + 1) // 2
        e = float('inf')
        l = float('-inf')
        if s <= half:
            for i in range(f):
                for j in range(s - f):
                    x, y = self.dp(half, i + 1, i + j + 2)
                    e = min(e, x)
                    l = max(l, y)
        else:
            s_prime = n + 1 - s
            mid = (2 * s - n - 1) // 2
            for i in range(f):
                for j in range(s_prime - f):
                    x, y = self.dp(half, i + 1, i + j + 2 + mid)
                    e = min(e, x)
                    l = max(l, y)
        self.E[n][f][s] = e + 1
        self.L[n][f][s] = l + 1
        return (e + 1, l + 1)
        
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        self.E = [[[0] * 30 for _ in range(30)] for _ in range(30)]
        self.L = [[[0] * 30 for _ in range(30)] for _ in range(30)]
        if firstPlayer > secondPlayer:
            firstPlayer, secondPlayer = secondPlayer, firstPlayer
        e, l = self.dp(n, firstPlayer, secondPlayer)
        return [e, l]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            firstPlayer = int(lines[1].split('=')[1].strip()[:-1])
            secondPlayer = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, firstPlayer, secondPlayer))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, firstPlayer, secondPlayer in dataset:
        results.append(solution.earliestAndLatest(n, firstPlayer, secondPlayer))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
