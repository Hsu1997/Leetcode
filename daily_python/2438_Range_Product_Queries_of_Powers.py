import os
import sys
from typing import List

class Solution:
    def powmod(self, base: int, pow: int) -> int:
        mod = int(1e9+7)
        res = 1
        while pow:
            if pow & 1:
                res = (res * base) % mod
            base = (base * base) % mod
            pow >>= 1
        return res

    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        power = []
        pow = 0
        while n:
            if n & 1:
                power.append(pow)
            n >>= 1
            pow += 1
        for i in range(1, len(power)):
            power[i] += power[i-1]
        ans = []
        for h, t in queries:
            ans.append(self.powmod(2, power[t] - (power[h - 1] if h > 0 else 0)))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            queries = [list(map(int, query.split(','))) for query in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, queries in dataset:
        results.append(solution.productQueries(n, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')