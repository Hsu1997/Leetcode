import os
import sys
from typing import List

class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        count = [[0] * (n+1) for _ in range(26)]
        ans = -1
        prev = s[0]
        curr_len = 1
        count[ord(prev)-ord('a')][curr_len] += 1
        for i in range(1, n):
            curr = s[i]
            if curr == prev:
                curr_len += 1
            else:
                prev = curr
                curr_len = 1
            count[ord(prev)-ord('a')][curr_len] += 1
        for i in range(26):
            for l in range(n-1, -1, -1):
                count[i][l] += count[i][l+1]
                if count[i][l] >= 3:
                    ans = max(ans, l)
                    break
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
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
        results.append(solution.maximumLength(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    