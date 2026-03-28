import os
import sys
from typing import List

class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        ans = ['?'] * n
        curr = ord('a')
        for i in range(n):
            if ans[i] == '?':
                if curr > ord('z'):
                    return ""
                ans[i] = chr(curr)
                curr += 1
                for j in range(i + 1, n):
                    if lcp[i][j] > 0:
                        ans[j] = ans[i]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if ans[i] != ans[j]:
                    if lcp[i][j] > 0:
                        return ""
                else:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    else:
                        if lcp[i][j] != lcp[i + 1][j + 1] + 1:
                            return ""
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            lcp = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(lcp)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for lcp in dataset:
        results.append(solution.findTheString(lcp))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')