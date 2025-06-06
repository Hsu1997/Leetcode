import os
import sys
from typing import List
from collections import deque

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        for u, v in edges:
            if u == v:
                return -1
            graph[u].append(v)
            indegree[v] += 1
        count = [[0] * 26 for _ in range(n)]
        queue = deque([])
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)
        visited = 0
        while queue:
            curr = queue.popleft()
            visited += 1
            count[curr][ord(colors[curr]) - ord('a')] += 1
            for neighbor in graph[curr]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
                for c in range(26):
                    count[neighbor][c] = max(count[neighbor][c], count[curr][c])
        if visited != n:
            return -1
        return max([max(node) for node in count])

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            colors = lines[0].split('=')[1].strip()[1:-2]
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((colors, edges))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for colors, edges in dataset:
        results.append(solution.largestPathValue(colors, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')