import os
import sys
from typing import List

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        adj = [[] for _ in range(n)]
        indegree = [0] * n
        ans = []
        for source in range(n):
            for des in graph[source]:
                adj[des].append(source)
                indegree[source] += 1
        que = []
        for i in range(n):
            if indegree[i] == 0:
                que.append(i)
        while que:
            curr = que.pop()
            ans.append(curr)
            for neighbor in adj[curr]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    que.append(neighbor)
        ans.sort()
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            graph = [list(map(int, row.split(','))) if row else [] for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(graph)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for graph in dataset:
        results.append(solution.eventualSafeNodes(graph))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')