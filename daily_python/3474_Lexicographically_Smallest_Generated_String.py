import os
import sys
from typing import List

class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        ans = ['a'] * (n + m - 1)
        fixed = [False] * (n + m - 1)
        for i in range(n):
            if str1[i] == 'T':
                for j in range(m):
                    if fixed[i + j] and ans[i + j] != str2[j]:
                        return ""
                    fixed[i + j] = True
                    ans[i + j] = str2[j]
        for i in range(n):
            if str1[i] == 'F':
                is_diff = False
                idx = -1
                for j in range(m - 1, -1, -1):
                    if ans[i + j] != str2[j]:
                        is_diff = True
                    if not fixed[i + j] and idx == -1:
                        idx = i + j
                if is_diff:
                    continue
                if idx == -1:
                    return ""
                ans[idx] = 'b'
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            str1 = lines[0].split('=')[1].strip()[1:-2]
            str2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((str1, str2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for str1, str2 in dataset:
        results.append(solution.generateString(str1, str2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')