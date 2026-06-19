import os
import sys
from typing import List
from sortedcontainers import SortedList

class SegmentTree:
    def __init__(self, obstacle: List[int]):
        self.n = 1 << (obstacle[-1].bit_length())
        self.t = [0] * (self.n * 2)
        for i in range(1, len(obstacle)):
            self.update(obstacle[i], obstacle[i] - obstacle[i-1])
        for i in range(self.n - 1, 0, -1):
            self.t[i] = max(self.t[i * 2], self.t[i * 2 + 1])

    def update(self, pos: int, val: int):
        pos += self.n
        self.t[pos] = val
        pos //= 2
        while pos:
            self.t[pos] = max(self.t[pos * 2], self.t[pos * 2 + 1])
            pos //= 2

    def query(self, pos: int)-> int:
        l = self.n
        r = self.n + pos
        res = 0
        while l <= r:
            res = max(res, self.t[l], self.t[r])
            l += 1
            r -= 1
            l //= 2
            r //= 2
        return res

class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        obstacle = SortedList([0, 50001])
        st = SegmentTree(obstacle)
        ans = []
        for query in queries:
            if query[0] == 1:
                pos = query[1]
                obstacle.add(pos)
                idx = obstacle.bisect_left(pos)
                st.update(obstacle[idx], obstacle[idx] - obstacle[idx-1])
                st.update(obstacle[idx+1], obstacle[idx+1] - pos)
            else:
                x = query[1]
                sz = query[2]
                ans.append(max(st.query(x), x - obstacle[obstacle.bisect_right(x) - 1]) >= sz)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            queries = [list(map(int, query.split(','))) for query in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(queries)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for queries in dataset:
        results.append(solution.getResults(queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
