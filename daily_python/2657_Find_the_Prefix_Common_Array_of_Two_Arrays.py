import os
import sys
from typing import Optional, List
from collections import deque

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        count = [0] * (n + 1)
        acc = 0
        ans = [0] * n
        for i in range(n):
            count[A[i]] += 1
            if count[A[i]] == 2:
                acc += 1
            count[B[i]] += 1
            if count[B[i]] == 2:
                acc += 1
            ans[i] = acc
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            A = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            B = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((A, B))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for A, B in dataset:
        results.append(solution.findThePrefixCommonArray(A, B))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')