import os
import sys
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        r, c = len(strs), len(strs[0])
        ans = 0
        for j in range(c):
            s = True
            for i in range(1, r):
                if strs[i][j] < strs[i-1][j]:
                    s = False
                    break
            ans += not s
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            strs = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(strs)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for strs in dataset:
        results.append(solution.minDeletionSize(strs))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')