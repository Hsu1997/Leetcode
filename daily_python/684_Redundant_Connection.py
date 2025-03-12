import os
import sys
from typing import List

class UnionFind:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
        self.rank = [1] * n
    def find(self, i: int)-> int:
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def combine(self, i: int, j: int)-> bool:
        s1 = self.find(i)
        s2 = self.find(j)
        if s1 == s2:
            return False
        if self.rank[s1] > self.rank[s2]:
            self.parents[s2] = s1
        elif self.rank[s1] < self.rank[s2]:
            self.parents[s1] = s2
        else:
            self.parents[s2] = s1
            self.rank[s1] += 1
        return True
        
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        u = UnionFind(n+1)
        for edge in edges:
            if not u.combine(edge[0], edge[1]):
                return edge
        return []

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(edges)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges in dataset:
        results.append(solution.findRedundantConnection(edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')