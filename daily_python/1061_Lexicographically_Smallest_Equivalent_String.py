import os
import sys
from typing import List

class Solution:
    def find(self, i: int)-> int:
        if self.group[i] == i:
            return i
        self.group[i] = self.find(self.group[i])
        return self.group[i]

    def combine(self, i: int, j: int) -> None:
        g1 = self.find(i)
        g2 = self.find(j)
        if g1 < g2:
            self.group[g2] = g1
        else:
            self.group[g1] = g2

    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        n = len(s1)
        self.group = [i for i in range(26)]
        for i in range(n):
            c1 = ord(s1[i]) - ord('a')
            c2 = ord(s2[i]) - ord('a')
            self.combine(c1, c2)
        return "".join([chr(self.find(ord(c) - ord('a')) + ord('a')) for c in baseStr])

    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s1 = lines[0].split('=')[1].strip()[1:-2]
            s2 = lines[1].split('=')[1].strip()[1:-2]
            baseStr = lines[2].split('=')[1].strip()[1:-2]
            dataset.append((s1, s2, baseStr))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s1, s2, baseStr in dataset:
        results.append(solution.smallestEquivalentString(s1, s2, baseStr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
