import os
import sys
from typing import List

class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        b = set(banned)
        acc = 0
        ans = 0
        for i in range(1, n+1):
            if acc + i > maxSum:
                return ans
            if i in b:
                continue
            else:
                acc += i
                ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            banned = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            n = int(lines[1].split('=')[1].strip()[:-1])
            maxSum = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((banned, n, maxSum))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for banned, n, maxSum in dataset:
        results.append(solution.maxCount(banned, n, maxSum))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
