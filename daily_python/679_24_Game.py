import os
import sys
from typing import List

class Solution:
    def dfs(self, curr: List[float]) -> bool:
        if len(curr) == 1:
            return abs(curr[0] - 24) < self.eps
        for i in range(len(curr)):
            for j in range(i + 1, len(curr)):
                if (i == j):
                    continue
                next = []
                for k in range(len(curr)):
                    if k != i and k != j:
                        next.append(curr[k])
                a, b = curr[i], curr[j]
                temp = [a + b, a - b, b - a, a * b]
                if b != 0:
                    temp.append(a / b)
                if a != 0:
                    temp.append(b / a)
                for op in temp:
                    next.append(op)
                    if self.dfs(next):
                        return True
                    next.pop()
        return False
    
    def judgePoint24(self, cards: List[int]) -> bool:
        self.eps = 1e-6
        cards = list(map(float, cards))
        return self.dfs(cards)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            cards = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(cards)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for cards in dataset:
        results.append(solution.judgePoint24(cards))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')