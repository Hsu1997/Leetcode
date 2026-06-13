import os
import sys
from typing import List
from collections import deque

class LCA:
    def __init__(self, edges: List[List[int]], root: int = 1):
        self.n = len(edges) + 1
        self.m = self.n.bit_length()
        self.d = [0] * (self.n + 1)
        self.e = [[] for _ in range(self.n + 1)]
        self.st = [[0] * self.m for _ in range(self.n + 1)]
        for u, v in edges:
            self.e[u].append(v)
            self.e[v].append(u)
        self.dfs(root, 0)
        for i in range(1, self.m):
            for x in range(1, self.n + 1):
                self.st[x][i] = self.st[self.st[x][i-1]][i-1]
        
    def dfs(self, x: int, p: int) -> None:
        self.st[x][0] = p
        for child in self.e[x]:
            if child == p:
                continue
            self.d[child] = self.d[x] + 1
            self.dfs(child, x)
        return
    
    def lca(self, u: int, v: int) -> int:
        if self.d[u] > self.d[v]:
            u, v = v, u
        for i in range(self.m - 1, -1, -1):
            if self.d[self.st[v][i]] >= self.d[u]:
                v = self.st[v][i]
        if u == v:
            return u
        for i in range(self.m - 1, -1, -1):
            if self.st[u][i] != self.st[v][i]:
                u = self.st[u][i]
                v = self.st[v][i]
        return self.st[u][0]
    
    def dis(self, u: int, v: int) -> int:
        return self.d[u] + self.d[v] - 2 * self.d[self.lca(u, v)]

def modpow(base: int, pow: int) -> int:
    mod = int(10 ** 9 + 7)
    res = 1
    while pow:
        if pow & 1:
            res = res * base % mod
        base = base * base % mod
        pow //= 2
    return res

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        lca = LCA(edges)
        ans = []
        for (u, v) in queries:
            d = lca.dis(u, v)
            ans.append(0 if d == 0 else modpow(2, d - 1))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            queries = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((edges, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges, queries in dataset:
        results.append(solution.assignEdgeWeights(edges, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')