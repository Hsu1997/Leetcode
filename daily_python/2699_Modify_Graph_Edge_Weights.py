import os
import sys
from typing import List
import heapq

class Solution:
    def Dijkstra(self, n: int, graph: List[List[int]], source: int, destination: int)-> int:
        shortest = [2e9] * n
        shortest[source] = 0
        pq = []
        heapq.heappush(pq, (0, source))
        while pq:
            d, v = heapq.heappop(pq)
            if d > shortest[v]:
                continue
            if v == destination:
                return d
            for neighbor, edge_len in graph[v]:
                if d + edge_len < shortest[neighbor]:
                    shortest[neighbor] = d + edge_len
                    heapq.heappush(pq, (shortest[neighbor], neighbor))
        return shortest[destination]

    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        for n1, n2, v in edges:
            if v != -1:
                graph[n1].append((n2, v))
                graph[n2].append((n1, v))
        curr_shortest_path = self.Dijkstra(n, graph, source, destination)
        if curr_shortest_path < target:
            return []
        finded = curr_shortest_path == target
        for i, (n1, n2, v) in enumerate(edges):
            if v != -1:
                continue
            if finded:
                edges[i][2] = 2e9
            else:
                edges[i][2] = 1
                graph[n1].append((n2,1))
                graph[n2].append((n1,1))
                temp_path = self.Dijkstra(n, graph, source, destination)
                if temp_path <= target:
                    finded = True
                    edges[i][2] += target - temp_path
        return edges if finded else []

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edge = lines[1].split('=')[1].strip()[2:-3].split('},{')
            edges = [list(map(int, e.split(','))) for e in edge]
            source = int(lines[2].split('=')[1].strip()[:-1])
            destination = int(lines[3].split('=')[1].strip()[:-1])
            target = int(lines[4].split('=')[1].strip()[:-1])
            dataset.append((n, edges, source, destination, target))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges, source, destination, target in dataset:
        # print(n, edges, source, destination, target)
        results.append(solution.modifiedGraphEdges(n, edges, source, destination, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')