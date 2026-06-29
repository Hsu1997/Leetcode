import os
import sys
from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        m = len(word)
        for pattern in patterns:
            n = len(pattern)
            lcp = [0] * n
            ptr = 0
            for i in range(1, n):
                while ptr > 0 and pattern[ptr] != pattern[i]:
                    ptr = lcp[ptr - 1]
                if pattern[ptr] == pattern[i]:
                    ptr += 1
                lcp[i] = ptr
            ptr = 0
            for i in range(m):
                while ptr > 0 and pattern[ptr] != word[i]:
                    ptr = lcp[ptr - 1]
                if pattern[ptr] == word[i]:
                    ptr += 1
                if ptr == n:
                    ans += 1
                    break
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            patterns = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            word = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((patterns, word))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for patterns, word in dataset:
        results.append(solution.numOfStrings(patterns, word))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')