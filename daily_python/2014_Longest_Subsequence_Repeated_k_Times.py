import os
import sys
from collections import deque, Counter

class Solution:
    def isSubsequence(self, s: str, sub: str, k: int) -> bool:
        pos = 0
        cnt = 0
        for c in s:
            if sub[pos] == c:
                pos += 1
            if pos == len(sub):
                pos = 0
                cnt += 1
                if cnt == k:
                    return True
        return False
    
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        ans = ""
        candidate = sorted([c for c, w in Counter(s).items() if w >= k], reverse = True)
        q = deque(candidate)
        while q:
            curr = q.popleft()
            if len(curr) > len(ans):
                ans = curr
            for c in candidate:
                temp = curr + c
                if self.isSubsequence(s, temp, k):
                    q.append(temp)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.longestSubsequenceRepeatedK(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')