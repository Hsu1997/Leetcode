import os
import sys
from typing import List

class Solution:
    def count(self, end: int) -> int:
        ans = 0
        base = 1
        cnt = 1
        while base <= end:
            ans += (min(base * 4 - 1, end) - base + 1) * cnt
            cnt += 1
            base *= 4
        return ans
    
    def minOperations(self, queries: List[List[int]]) -> int:
        ans = 0
        for start, end in queries:
            ans += (self.count(end) - self.count(start - 1) + 1) // 2
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
        results.append(solution.minOperations(queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')