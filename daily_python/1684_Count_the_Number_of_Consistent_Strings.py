import os
import sys
from typing import List

class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans = 0
        allow = 0
        for c in allowed:
            allow |= 1 << (ord(c) - ord('a'))
        for word in words:
            is_allowed = True
            for c in word:
                if not ((1 << (ord(c) - ord('a'))) & allow):
                    is_allowed = False
                    break
            ans += is_allowed
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            allowed = lines[0].split('=')[1][2:-2]
            words = lines[1].split('=')[1][3:-3].split("\",\"")
            dataset.append((allowed, words))
            print(allowed, words)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for allowed, words in dataset:
        results.append(solution.countConsistentStrings(allowed, words))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')