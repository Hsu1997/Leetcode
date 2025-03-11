import os
import sys
from typing import List

class Solution:
    def _valid(self, count):
        return all(c > 0 for c in count)
    
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        start = end = 0
        ans = 0
        count = [0, 0, 0]
        while end < n:
            count[ord(s[end]) - ord('a')] += 1
            while start < end and self._valid(count):
                ans += n - end
                count[ord(s[start]) - ord('a')] -= 1
                start += 1
            end += 1
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
        results.append(solution.numberOfSubstrings(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    