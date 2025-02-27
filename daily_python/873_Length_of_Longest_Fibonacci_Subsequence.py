import os
import sys
from typing import List

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0] * n for _ in range(n)]
        for curr in range(2, n):
            start = 0
            end = curr - 1
            while start < end:
                presum = arr[start] + arr[end]
                if presum < arr[curr]:
                    start += 1
                elif presum > arr[curr]:
                    end -= 1
                else:
                    dp[end][curr] = dp[start][end] + 1
                    start += 1
                    end -= 1
        ans = max(max(d) for d in dp)
        return ans + 2 if ans else 0
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(arr)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.lenLongestFibSubseq(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')