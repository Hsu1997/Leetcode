import os
import sys
from typing import List

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        ans = 0
        m = [0] * 26
        for c in s:
            m[ord(c) - ord('a')] += 1
        for i in range(26):
            curr = chr(ord('a') + i)
            count = m.copy()
            left = 0
            right = n-1
            while left < n and s[left] != curr:
                count[ord(s[left]) - ord('a')] -= 1
                left += 1
            while right > left and s[right] != curr:
                count[ord(s[right]) - ord('a')] -= 1
                right -= 1
            if left == right:
                continue
            count[i] -= 2
            temp = 0
            for v in count:
                if v > 0:
                    temp += 1
            ans += temp
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
        results.append(solution.countPalindromicSubsequence(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')