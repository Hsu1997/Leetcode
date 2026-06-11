import os
import sys
from typing import List
from collections import deque

class Solution:
    def modPow(self, base, pow) -> int:
        mod = 10 ** 9 + 7
        res = 1
        while pow:
            if pow & 1:
                res = res * base % mod
            base = base * base % mod
            pow >>= 1
        return res
    
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        graph = [[] for _ in range(n)]
        for edge in edges:
            a = edge[0] - 1
            b = edge[1] - 1
            graph[a].append(b)
            graph[b].append(a)
        que = deque([0])
        visited = [False] * n
        visited[0] = True
        depth = 0
        while que:
            s = len(que)
            depth += 1
            for _ in range(s):
                curr = que.popleft()
                for child in graph[curr]:
                    if visited[child]:
                        continue
                    visited[child] = True
                    que.append(child)
        ans = self.modPow(2, depth - 2)
        return ans

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
        results.append(solution.assignEdgeWeights(edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')