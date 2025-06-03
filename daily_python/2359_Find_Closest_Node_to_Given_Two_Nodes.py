import os
import sys
from typing import List

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        time1 = [-1] * n
        time2 = [-1] * n
        t = 0
        while node1 != -1 and time1[node1] == -1:
            time1[node1] = t
            node1 = edges[node1]
            t += 1
        t = 0
        while node2 != -1 and time2[node2] == -1:
            time2[node2] = t
            node2 = edges[node2]
            t += 1
        ans = -1
        dist = float('inf')
        for i in range(n):
            if time1[i] != -1 and time2[i] != -1:
                curr = max(time1[i], time2[i])
                if curr < dist:
                    dist = curr
                    ans = i
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            node1 = int(lines[1].split('=')[1].strip()[:-1])
            node2 = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((edges, node1, node2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges, node1, node2 in dataset:
        results.append(solution.closestMeetingNode(edges, node1, node2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')