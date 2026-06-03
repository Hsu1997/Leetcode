import os
import sys
from typing import List

class Solution:
    def dp(self, start, arr, d) -> int:
        if self.memo[start] != -1:
            return self.memo[start]
        res = 0
        for i in range(start - 1, max(-1, start - d - 1), -1):
            if arr[i] >= arr[start]:
                break
            res = max(res, self.dp(i, arr, d))
        for i in range(start + 1, min(len(arr), start + d + 1)):
            if arr[i] >= arr[start]:
                break
            res = max(res, self.dp(i, arr, d))
        self.memo[start] = res + 1
        return self.memo[start]
    
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        ans = 0
        self.memo = [-1] * n
        for start in range(n):
            ans = max(ans, self.dp(start, arr, d))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            d = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((arr, d))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, d in dataset:
        results.append(solution.maxJumps(arr, d))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')