import os
import sys
from typing import List

class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        ans = set()
        max_len = -1
        n = len(s)
        remain_right = [0] * n
        for i in range(n - 2, -1, -1):
            remain_right[i] = remain_right[i+1] + (s[i + 1] == ')')
        curr = []
        def dfs(idx: int, left: int) -> None:
            nonlocal max_len
            if idx == n:
                if left == 0:
                    l = len(curr)
                    if l >= max_len:
                        if l > max_len:
                            ans.clear()
                            max_len = l
                        ans.add(''.join(curr))
                return
            else:
                c = s[idx]
                if c not in '()':
                    curr.append(c)
                    dfs(idx + 1, left)
                    curr.pop()
                else:
                    dfs(idx + 1, left)
                    if c == '(':
                        if left + 1 <= remain_right[idx]:
                            curr.append(c)
                            dfs(idx + 1, left + 1)
                            curr.pop()
                    else:
                        if left > 0:
                            curr.append(c)
                            dfs(idx + 1, left - 1)
                            curr.pop()
        dfs(0, 0)
        return list(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1][1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.removeInvalidParentheses(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')