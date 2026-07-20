import os
import sys
from typing import List

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        cnt = [0] * 26
        visited = [False] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        ans = []
        for c in s:
            if not visited[ord(c) - ord('a')]:
                while ans and ord(c) < ord(ans[-1]) and cnt[ord(ans[-1]) - ord('a')] > 0:
                    visited[ord(ans[-1]) - ord('a')] = False
                    ans.pop()
                visited[ord(c) - ord('a')] = True
                ans.append(c)
            cnt[ord(c) - ord('a')] -= 1
        return "".join(ans)
    
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
        results.append(solution.smallestSubsequence(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')