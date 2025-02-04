import os
import sys
from typing import List

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree = [0] * n
        for edge in edges:
            indegree[edge[1]] += 1
        ans = -1
        for i in range(n):
            if indegree[i] == 0:
                if ans == -1:
                    ans = i
                else:
                    return -1
        return ans

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
        results.append(solution.findChampion(n, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')