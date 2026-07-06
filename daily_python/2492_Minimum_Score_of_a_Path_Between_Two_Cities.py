import os
import sys
from typing import List

class DisjointSet:
    def __init__(self, n: int):
        self.v = [i for i in range(n)]
    def find(self, i) -> int:
        if self.v[i] != i:
            self.v[i] = self.find(self.v[i])
        return self.v[i]
    def combine(self, i: int, j: int) -> bool:
        x = self.find(i)
        y = self.find(j)
        if x == y:
            return False
        self.v[y] = x
        return True

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        D = DisjointSet(n)
        for s, e, r in roads:
            D.combine(s-1, e-1)
        ans = float('inf')
        for s, e, r in roads:
            if D.find(s-1) == D.find(0):
                ans = min(ans, r)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            roads = [list(map(int, road.split(','))) for road in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, roads))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, roads in dataset:
        results.append(solution.minScore(n, roads))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')