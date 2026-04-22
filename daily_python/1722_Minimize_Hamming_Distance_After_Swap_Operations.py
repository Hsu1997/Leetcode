import os
import sys
from typing import List
from collections import defaultdict

class DSU:
    def __init__(self, n: int):
        self.n = n
        self.parents = [i for i in range(n)]
    def find(self, i) -> int:
        if self.parents[i] != i:
            self.parents[i] = self.find(self.parents[i])
        return self.parents[i]
    def combine(self, i: int, j: int) -> None:
        x = self.find(i)
        y = self.find(j)
        self.parents[y] = x
    def allSet(self) -> dict:
        s = defaultdict(list)
        for i in range(self.n):
            parent = self.find(i)
            s[parent].append(i)
        return s
    
class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        d = DSU(n)
        ans = 0
        for x, y in allowedSwaps:
            d.combine(x, y)
        m = d.allSet()
        for group in m.values():
            cnt = defaultdict(int)
            for g in group:
                cnt[target[g]] += 1
            for g in group:
                cnt[source[g]] -= 1
            for c in cnt.values():
                if c > 0:
                    ans += c
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            source = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            target = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            allowedSwaps = [list(map(int, l.split(','))) for l in lines[2].split('=')[1].strip()[2:-3].split('},{') if l]
            dataset.append((source, target, allowedSwaps))
    return dataset

if __name__ == "__main__":
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for source, target, allowedSwaps in dataset:
        results.append(solution.minimumHammingDistance(source, target, allowedSwaps))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')