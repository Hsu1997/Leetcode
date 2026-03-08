import os
import sys
from typing import List

class Solution:
    def duo(self, s: str, c1: chr, c2: chr) -> int:
        m = {}
        n = len(s)
        delta = 0
        m[0] = -1
        ans = 0
        for i in range(n):
            if s[i] != c1 and s[i] != c2:
                delta = 0
                m.clear()
                m[0] = i
            else:
                delta += 1 if s[i] == c1 else -1
                if delta in m:
                    ans = max(ans, i - m[delta])
                else:
                    m[delta] = i
        return ans
                    
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        c = 1
        ans = 1
        for i in range(1, n):
            if s[i] == s[i-1]:
                c += 1
                ans = max(ans, c)
            else:
                c = 1
        ans = max(ans, self.duo(s, 'a', 'b'), self.duo(s, 'a', 'c'), self.duo(s, 'b', 'c'))
        m = {}
        cnt = [0] * 3
        m[(0,0)] = -1
        for i in range(n):
            cnt[ord(s[i]) - ord('a')] += 1
            curr = (cnt[1] - cnt[0], cnt[2] - cnt[0])
            if curr in m:
                ans = max(ans, i - m[curr])
            else:
                m[curr] = i
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
        results.append(solution.longestBalanced(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')