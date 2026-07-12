import os
import sys
from typing import List

class Solution:
    def valid(self, mid: int, n: int, g: List[List[int]], k: int) -> bool:
        memo = [-1] * n
        memo[n - 1] = 0
        return self.dp(0, mid, n, memo, g) <= k
    
    def dp(self, u: int, mid: int, n: int, memo: List[int], g: List[List[int]])-> int:
        if memo[u] != -1:
            return memo[u]
        res = float('inf')
        for v, w in g[u]:
            if w < mid:
                continue
            res = min(res, w + self.dp(v, mid, n, memo, g))
        memo[u] = res
        return memo[u]
    
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)
        g = [[] for _ in range(n)]
        l, r = float('inf'), 0
        for u, v, w in edges:
            if not online[u] or not online[v] or w > k:
                continue
            g[u].append((v, w))
            l = min(l, w)
            r = max(r, w)
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if self.valid(mid, n, g, k):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            online = [True if i == 'true' else False for i in lines[1].split('=')[1].strip()[1:-2].split(',')]
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((edges, online, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges, online, k in dataset:
        results.append(solution.findMaxPathScore(edges, online, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')