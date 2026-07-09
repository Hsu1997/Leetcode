import os
import sys
from typing import List

mod = 10 ** 9 + 7
pow10 = [1] * 100001
for i in range(1, 100001):
    pow10[i] = pow10[i-1] * 10 % mod

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        acc = [0] * (n + 1)
        x = [0] * (n + 1)
        cnt = [0] * (n + 1)
        for i, c in enumerate(s):
            d = int(c)
            acc[i + 1] = acc[i] + d
            x[i + 1] = x[i] if d == 0 else (x[i] * 10 + d) % mod
            cnt[i + 1] = cnt[i] + (d > 0)
        m = len(queries)
        ans = [0] * m
        for i in range(m):
            l = queries[i][0]
            r = queries[i][1] + 1
            ans[i] = (x[r] - x[l] * pow10[cnt[r] - cnt[l]]) * (acc[r] - acc[l]) % mod
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((s, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, queries in dataset:
        results.append(solution.sumAndMultiply(s, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')