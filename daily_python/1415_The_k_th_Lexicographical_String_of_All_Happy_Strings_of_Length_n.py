import os
import sys
from typing import List

class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        total = 3 * (1 << (n - 1))
        if k > total:
            return ""
        ans = ['a'] * n
        total = 1 << (n - 1)
        k -= 1
        ans[0] = chr(ord('a') + k // total)
        k %= total
        next_smaller_char = {'a' : 'b', 'b' : 'a', 'c' : 'a'}
        next_greater_char = {'a' : 'c', 'b' : 'c', 'c' : 'b'}
        for i in range(1, n):
            total = 1 << (n - 1 - i)
            if k // total == 0:
                ans[i] = next_smaller_char[ans[i-1]]
            else:
                ans[i] = next_greater_char[ans[i-1]]
            k %= total
        return "".join(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k in dataset:
        results.append(solution.getHappyString(n, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')