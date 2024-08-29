import os
import sys
from typing import List

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        class UnionSet:
            def __init__(self, n):
                self.parents = [i for i in range(n)]
                self.rank = [0] * n
            def find(self, i):
                if i == self.parents[i]:
                    return i
                else:
                    return self.find(self.parents[i])
            def merge(self, i, j):
                root_i = self.find(i)
                root_j = self.find(j)
                if root_i != root_j:
                    if self.rank[root_i] < self.rank[root_j]:
                        self.parents[root_i] = root_j
                    elif self.rank[root_i] > self.rank[root_j]:
                        self.parents[root_j] = root_i
                    else:
                        self.parents[root_j] = root_i
                        self.rank[root_i] += 1
        n = len(stones)
        s = UnionSet(30000)
        for row, col in stones:
            s.merge(row, col + 20000)
        count_set = set()
        for row, col in stones:
            count_set.add(s.find(row))
            count_set.add(s.find(col + 20000))
        return n - len(count_set)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            stone = lines[0].split('=')[1].strip()[2:-3].split('},{')
            stones = [list(map(int,s.split(','))) for s in stone]
            dataset.append(stones)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for stones in dataset:
        results.append(solution.removeStones(stones))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')