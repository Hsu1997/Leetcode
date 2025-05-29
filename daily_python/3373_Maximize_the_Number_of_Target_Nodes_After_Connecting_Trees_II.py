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
    
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        m = len(edges1) + 1
        n = len(edges2) + 1
        g1 = self.transToGraph(edges1)
        g2 = self.transToGraph(edges2)
        c1 = [-1] * m
        c2 = [-1] * n
        c1[0] = 0
        color = 1
        que = deque([0])
        while que:
            k = len(que)
            for _ in range(k):
                curr = que.popleft()
                for neighbor in g1[curr]:
                    if c1[neighbor] == -1:
                        c1[neighbor] = color
                        que.append(neighbor)
            color ^= 1
        
        c2[0] = 0
        color = 1
        que = deque([0])
        while que:
            k = len(que)
            for _ in range(k):
                curr = que.popleft()
                for neighbor in g2[curr]:
                    if c2[neighbor] == -1:
                        c2[neighbor] = color
                        que.append(neighbor)
            color ^= 1
        M = max(sum(1 if c == 0 else 0 for c in c2), sum(1 if c == 1 else 0 for c in c2))
        # print(c1, c2, M)
        ans = [0] * m
        s1 = sum(1 if c == 0 else 0 for c in c1)
        s2 = sum(1 if c == 1 else 0 for c in c1)
        # print(s1, s2)
        for i in range(m):
            ans[i] = M + (s1 if c1[i] == 0 else s2)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges1 = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            edges2 = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((edges1, edges2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges1, edges2 in dataset:
        results.append(solution.maxTargetNodes(edges1, edges2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')