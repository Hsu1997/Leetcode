import sys
import os
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, l = len(strs), len(strs[0])
        dp = [1] * l
        for j in range(l-2, -1, -1):
            for k in range(j+1, l):
                if all(strs[i][j] <= strs[i][k] for i in range(n)):
                    dp[j] = max(dp[j], 1 + dp[k])
        ans = min(l - dp[j] for j in range(l))
        return ans

def readDataSet(filename: str) -> None:
    dataset = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            strs = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(strs)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for strs in dataset:
        results.append(solution.minDeletionSize(strs))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')