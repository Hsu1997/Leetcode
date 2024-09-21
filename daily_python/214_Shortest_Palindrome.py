import os
import sys
from typing import List

class Solution:
    def KMP(self, s: str)-> List[int]:
        table = [0] * len(s)
        l = 0
        for i in range(1, len(s)):
            while l > 0 and s[i] != s[l]:
                l = table[l-1]
            if s[i] == s[l]:
                l += 1
            table[i] = l
        return table

    def shortestPalindrome(self, s: str) -> str:
        new_s = s + '#' + s[::-1]
        table = self.KMP(new_s)
        return s[table[-1]:][::-1] + s
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1][2:-2]
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
        results.append(solution.shortestPalindrome(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')