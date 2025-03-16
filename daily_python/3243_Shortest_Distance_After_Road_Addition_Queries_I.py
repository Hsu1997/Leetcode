import os
import sys
from typing import List, Optional
from collections import deque

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        self.graph = [[] for _ in range(n)]
        for i in range(n-1):
            self.graph[i].append(i+1)
        q = len(queries)
        ans = []
        for start, end in queries:
            self.graph[start].append(end)
            ans.append(self.bfs(n))
        return ans
    def bfs(self, n):
        que = deque([0])
        visited = [False] * n
        visited[0] = True
        path = 0
        while que:
            k = len(que)
            for _ in range(k):
                curr = que.popleft()
                if curr == n-1:
                    return path
                for neighbor in self.graph[curr]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        que.append(neighbor)
            path += 1
        return -1

def readDataSet(filename):
    dataset = []
    with open(filename) as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, queries))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, queries in dataset:
        results.append(solution.shortestDistanceAfterQueries(n, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')