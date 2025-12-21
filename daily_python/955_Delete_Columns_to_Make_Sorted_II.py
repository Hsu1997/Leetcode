import os
import sys
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, l = len(strs), len(strs[0])
        already_sorted = [False] * n
        ans = 0
        for j in range(l):
            temp_sorted = [False] * n
            need_delete = False
            for i in range(1, n):
                if already_sorted[i]:
                    continue
                else:
                    if strs[i][j] < strs[i-1][j]:
                        need_delete = True
                        break
                    elif strs[i][j] > strs[i-1][j]:
                        temp_sorted[i] = True
            if need_delete:
                ans += 1
            else:
                for i in range(n):
                    already_sorted[i] |= temp_sorted[i]
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