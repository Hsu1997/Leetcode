import os
import sys
from typing import List
from collections import deque

class Solution:
    def transToGraph(self, edges):
        n = len(edges) + 1
        graph = [[] for _ in range(n)]
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        return graph
    
    def countTarget(self, graph, k):
        n = len(graph)
        ans = [0] * n
        for start in range(n):
            visited = [False] * n
            que = deque([start])
            visited[start] = True
            for _ in range(k+1):
                temp = len(que)
                while temp > 0:
                    curr = que.popleft()
                    ans[start] += 1
                    for neighbor in graph[curr]:
                        if visited[neighbor] == False:
                            visited[neighbor] = True
                            que.append(neighbor)
                    temp -= 1
        return ans

    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        if k == 0:
            return [1] * (len(edges1) + 1)
        g1 = self.transToGraph(edges1)
        g2 = self.transToGraph(edges2)
        t1 = self.countTarget(g1, k)
        if k == 1:
            return [i + 1 for i in t1]
        else:
            M = max(self.countTarget(g2, k-1))
            return [i + M for i in t1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges1 = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            edges2 = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((edges1, edges2, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges1, edges2, k in dataset:
        results.append(solution.maxTargetNodes(edges1, edges2, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')