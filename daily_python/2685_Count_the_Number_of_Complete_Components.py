import os
import sys
from typing import List

class UnionFind:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.size = [1] * n
    def find(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def combine(self, i, j):
        rootA = self.find(i)
        rootB = self.find(j)
        if rootA == rootB:
            return
        if self.size[rootA] < self.size[rootB]:
            rootA, rootB = rootB, rootA
        self.parents[rootB] = rootA
        self.size[rootA] += self.size[rootB]
    def groupSize(self, i):
        return self.size[self.find(i)]

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        U = UnionFind(n)
        edge_count = [0] * n
        for start, end in edges:
            U.combine(start, end)
            edge_count[start] += 1
            edge_count[end] += 1
        component = {}
        for i in range(n):
            if U.parents[i] == i:
                component[i] = []
        for i in range(n):
            component[U.find(i)].append(i)
        ans = 0
        for group, nodeSet in component.items():
            complete = True
            s = U.groupSize(nodeSet[0])
            for node in nodeSet:
                if edge_count[node] != s - 1:
                    complete = False
                    break
            if complete:
                ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, edges))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges in dataset:
        results.append(solution.countCompleteComponents(n, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')