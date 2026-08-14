import os
import sys
from typing import List

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        start = 0
        cnt = [0] * 26
        for end in range(n):
            curr = ord(s[end]) - ord('a')
            cnt[curr] += 1
            while cnt[curr] > 2:
                cnt[ord(s[start]) - ord('a')] -= 1
                start += 1
            ans = max(ans, end - start + 1)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
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
        results.append(solution.maximumLengthSubstring(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')