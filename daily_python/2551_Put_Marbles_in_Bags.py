import os
import sys
from typing import List
import heapq

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        pairweight = []
        for i in range(n-1):
            pairweight.append(weights[i] + weights[i+1])
        pairweight = sorted(pairweight)
        ans = 0
        for i in range(k-1):
            ans += pairweight[n-2-i] - pairweight[i]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            weights = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((weights, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for weights, k in dataset:
        results.append(solution.putMarbles(weights, k))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')