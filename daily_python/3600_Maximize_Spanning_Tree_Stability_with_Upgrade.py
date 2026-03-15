import os
import sys
from typing import List

class UnionFind:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
    def find(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def join(self, i, j) -> bool:
        a = self.find(i)
        b = self.find(j)
        if a == b:
            return False
        self.parents[a] = b
        return True
    
class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        ans = 10**9
        u = UnionFind(n)
        connected = 1
        candidate = []
        for edge in edges:
            n1 = edge[0]
            n2 = edge[1]
            w = edge[2]
            must = edge[3]
            if must:
                if not u.join(n1, n2):
                    return -1
                ans = min(ans, w)
                connected += 1
            else:
                candidate.append(edge)
        candidate.sort(key = lambda x : x[2], reverse = True)
        for edge in candidate:
            if not u.join(edge[0], edge[1]):
                continue
            if connected + k >= n:
                ans = min(ans, edge[2] * 2)
            else:
                ans = min(ans, edge[2])
            connected += 1
            if connected == n:
                return ans
        return ans if connected == n else -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((n, edges, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges, k in dataset:
        results.append(solution.maxStability(n, edges, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')