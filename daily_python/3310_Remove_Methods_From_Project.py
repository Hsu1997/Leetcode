import os
import sys
from typing import List
from collections import deque

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        for s, e in invocations:
            graph[s].append(e)
            indegree[e] += 1
        que = deque([k])
        suspicious = set([k])
        while que:
            curr = que.popleft()
            for neighbor in graph[curr]:
                indegree[neighbor] -= 1
                if neighbor not in suspicious:
                    suspicious.add(neighbor)
                    que.append(neighbor)
        for sus in suspicious:
            if indegree[sus] != 0:
                return [i for i in range(n)]
        return [i for i in range(n) if i not in suspicious]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            invocations = [list(map(int, edge.split(','))) for edge in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, k, invocations))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k, invocations in dataset:
        results.append(solution.remainingMethods(n, k, invocations))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')