import os
import sys
from typing import List
from collections import deque

class Solution:
    def create_graph(self, edges):
        n = len(edges)+1
        graph = [[] for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        return graph
    
    def bfs_farest(self, graph, start_node):
        n = len(graph)
        visited = [False] * n
        farest_node = -1
        diameter = 0
        visited[start_node] = True
        que = deque([start_node])
        while que:
            curr_level_size = len(que)
            for _ in range(curr_level_size):
                curr = que.popleft()
                farest_node = curr
                for neighbor in graph[curr]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        que.append(neighbor)
            if que:
                diameter += 1
        return (farest_node, diameter)

    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        g1 = self.create_graph(edges1)
        g2 = self.create_graph(edges2)
        node1, _ = self.bfs_farest(g1, 0)
        node2, _ = self.bfs_farest(g2, 0)
        _, d1 = self.bfs_farest(g1, node1)
        _, d2 = self.bfs_farest(g2, node2)
        return max(d1, d2, (d1+1)//2 + (d2+1)//2 + 1)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges1_str = lines[0].split('=')[1].strip()
            edges2_str = lines[1].split('=')[1].strip()
            edges1 = [] if edges1_str == "{};" else [list(map(int, edge.split(','))) for edge in edges1_str[2:-3].split('},{')]
            edges2 = [] if edges2_str == "{};" else [list(map(int, edge.split(','))) for edge in edges2_str[2:-3].split('},{')]
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
        results.append(solution.minimumDiameterAfterMerge(edges1, edges2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
