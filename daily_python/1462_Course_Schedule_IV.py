import os
import sys
from typing import List, Optional
from collections import deque, defaultdict

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: Optional[List[List[int]]], queries: List[List[int]]) -> List[bool]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for edge in prerequisites:
            if not edge:
                continue
            graph[edge[0]].append(edge[1])
            indegree[edge[1]] += 1
        que = deque([i for i in range(numCourses) if indegree[i] == 0])
        nodePrerequisites = defaultdict(set)
        while que:
            curr = que.popleft()
            for neighbor in graph[curr]:
                nodePrerequisites[neighbor].add(curr)
                for prereq in nodePrerequisites[curr]:
                    nodePrerequisites[neighbor].add(prereq)
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    que.append(neighbor)
        ans = []
        for q in queries:
            ans.append(q[0] in nodePrerequisites[q[1]])
        return ans

def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            numCourses = int(lines[0].split('=')[1].strip()[:-1])
            prerequisites = [list(map(int, i.split(','))) if i else [] for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            queries = [list(map(int, i.split(','))) if i else [] for i in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((numCourses, prerequisites, queries))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    solution = Solution()
    results = []
    for numCourses, prerequisites, queries in dataset:
        results.append(solution.checkIfPrerequisite(numCourses, prerequisites, queries))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')