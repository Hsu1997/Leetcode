import sys
import os
from typing import List

class DisjointSetUnion:
    def __init__(self, size: int):
        self.n = size
        self.group = self.n
        self.parents = [i for i in range(self.n)]
    
    def find(self, i: int)-> int:
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    
    def union(self, i: int, j: int)-> None:
        u = self.find(i)
        v = self.find(j)
        if u != v:
            self.parents[u] = v
            self.group -= 1

    def __len__(self):
        return self.group

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        D = DisjointSetUnion(n * n * 4)
        for i in range(n):
            for j in range(n):
                index = i * n + j
                if i > 0:
                    D.union(index * 4, (index - n) * 4 + 2)
                if j > 0:
                    D.union(index * 4 + 3, (index - 1) * 4 + 1)
                if grid[i][j] != '/':
                    D.union(index * 4, index * 4 + 1)
                    D.union(index * 4 + 2, index * 4 + 3)
                if grid[i][j] != '\\':
                    D.union(index * 4, index * 4 + 3)
                    D.union(index * 4 + 1, index * 4 + 2)
        return len(D)
    
def readDataSet(filename: str) -> None:
    dataset = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n')
        for block in blocks:
            data = block.split('=')[1].strip()[1:-2].replace('\"', "").replace('\\\\','\\').split(',')
            dataset.append(data)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for grid in dataset:
        results.append(solution.regionsBySlashes(grid))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')