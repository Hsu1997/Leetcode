import os
import sys
from typing import List
import heapq

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for [v1, v2, w] in edges:
            graph[v1].append((v2, w))
            graph[v2].append((v1, w * 2))
        d = [float('inf')] * n
        d[0] = 0
        pq = [(0, 0)]
        while pq:
            dis, node = heapq.heappop(pq)
            if d[node] != dis:
                continue
            if node == n - 1:
                return dis
            for next, w in graph[node]:
                if dis + w < d[next]:
                    d[next] = dis + w
                    heapq.heappush(pq, (d[next], next))
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edges = [list(map(int, point.split(','))) for point in lines[1].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.minCost(n, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')