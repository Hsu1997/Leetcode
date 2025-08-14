import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        cnt = defaultdict(int)
        for f in basket1:
            cnt[f] += 1
        for f in basket2:
            cnt[f] -= 1
        move = []
        m = float('inf')
        for v, c in cnt.items():
            if c % 2 == 1:
                return -1
            m = min(m, v)
            for i in range(abs(c) // 2):
                move.append(v)
        move.sort()
        ans = 0
        for i in range(len(move) // 2):
            ans += min(m * 2, move[i])
        print(move)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            basket1 = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            basket2 = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((basket1, basket2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for basket1, basket2 in dataset:
        results.append(solution.minCost(basket1, basket2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')