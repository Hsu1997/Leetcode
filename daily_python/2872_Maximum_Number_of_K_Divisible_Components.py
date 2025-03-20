import os
import sys
from typing import List

class Solution:
    def dfs(self, node: int) -> int:
        s = self.values[node] % self.k
        self.visited[node] = True
        for neighbor in self.graph[node]:
            if not self.visited[neighbor]:
                s = (s + self.dfs(neighbor)) % self.k
        if s % self.k == 0:
            self.ans += 1
        return s
    
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        self.ans = 0
        self.graph = [[] for _ in range(n)]
        for start, end in edges:
            self.graph[start].append(end)
            self.graph[end].append(start)
        self.values = values
        self.k = k
        self.visited = [False] * n
        self.dfs(0)
        return self.ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            values = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[3].split('=')[1].strip()[:-1])
            dataset.append((n, edges, values, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges, values, k in dataset:
        results.append(solution.maxKDivisibleComponents(n, edges, values, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')