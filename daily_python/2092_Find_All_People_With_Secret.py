import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        m = len(meetings)
        meetings.sort(key = lambda x : x[2])
        ptr = 0
        know = [False] * n
        know[0] = know[firstPerson] = True
        while ptr < m:
            t = meetings[ptr][2]
            graph = defaultdict(list)
            que = []
            visited = set()
            while ptr < m and meetings[ptr][2] == t:
                n1, n2 = meetings[ptr][0], meetings[ptr][1]
                graph[n1].append(n2)
                graph[n2].append(n1)
                if know[n1] and n1 not in visited:
                    visited.add(n1)
                    que.append(n1)
                if know[n2] and n2 not in visited:
                    visited.add(n2)
                    que.append(n2)
                ptr += 1
            while que:
                curr = que.pop()
                for neighbor in graph[curr]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        know[neighbor] = True
                        que.append(neighbor)
        ans = [x for x in range(n) if know[x] == 1]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            meetings = [list(map(int, meeting.split(','))) for meeting in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            firstPerson = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, meetings, firstPerson))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, meetings, firstPerson in dataset:
        results.append(solution.findAllPeople(n, meetings, firstPerson))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')