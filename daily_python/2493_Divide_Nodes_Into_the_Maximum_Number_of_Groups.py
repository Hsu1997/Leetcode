import os
import sys
from typing import List
from collections import deque

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        self.graph = [[] for _ in range(n)]
        for edge in edges:
            self.graph[edge[0] - 1].append(edge[1] - 1)
            self.graph[edge[1] - 1].append(edge[0] - 1)
        color = [-1] * n
        for node in range(n):
            if color[node] == -1:
                color[node] = 0
                if not self.check_bipartite(color, node):
                    return -1
        dist = [0] * n
        for node in range(n):
            dist[node] = self.bfs(node)
        
        ans = 0
        visited = [False] * n
        for node in range(n):
            if not visited[node]:
                curr_group = 0
                visited[node] = True
                que = deque([node])
                while que:
                    curr = que.popleft()
                    curr_group = max(curr_group, dist[curr])
                    for neighbor in self.graph[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            que.append(neighbor)
                ans += curr_group
        return ans
    
    def check_bipartite(self, color: List[int], node: int) -> bool:
        for neighbor in self.graph[node]:
            if color[neighbor] == color[node]:
                return False
            if color[neighbor] == -1:
                color[neighbor] = color[node] ^ 1
                if not self.check_bipartite(color, neighbor):
                    return False
        return True
    
    def bfs(self, node: int) -> int:
        visited = [False] * len(self.graph)
        que = deque([node])
        visited[node] = True
        dis = 0
        while que:
            k = len(que)
            for _ in range(k):
                curr = que.popleft()
                for neighbor in self.graph[curr]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        que.append(neighbor)
            dis += 1
        return dis

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
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
        results.append(solution.magnificentSets(n, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')