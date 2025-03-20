import os
import sys
from typing import List

class UnionFind:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
        self.rank = [1] * n
        self.cost = [(1 << 30) - 1] * n
    def find(self, i: int) -> int:
        self.parents[i] = self.find(self.parents[i]) if self.parents[i] != i else self.parents[i]
        return self.parents[i]
    def combine(self, i: int, j: int, w: int) -> bool:
        rootA = self.find(i)
        rootB = self.find(j)
        self.cost[rootA] &= w
        self.cost[rootB] &= w
        if rootA == rootB:
            return False
        if self.rank[rootA] < self.rank[rootB]:
            rootA, rootB = rootB, rootA
        self.parents[rootB] = rootA
        if self.rank[rootA] == self.rank[rootB]:
            self.rank[rootA] += 1
        self.cost[rootA] &= self.cost[rootB]
        return True
    def query_cost(self, i: int, j: int) -> int:
        rootA = self.find(i)
        rootB = self.find(j)
        if rootA != rootB:
            return -1
        return self.cost[rootA]
    
class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        G = UnionFind(n)
        for n1, n2, w in edges:
            G.combine(n1, n2, w)
        ans = []
        for q in query:
            ans.append(G.query_cost(q[0], q[1]))
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
            query = [list(map(int, edge.split(','))) for edge in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, edges, query))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges, query in dataset:
        results.append(solution.minimumCost(n, edges, query))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')