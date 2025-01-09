import os
import sys
from typing import List

class Solution:
    def is_prefix(self, pattern, word):
        if len(pattern) > len(word):
            return False
        for i in range(len(pattern)):
            if pattern[i] != word[i]:
                return False
        return True
    def is_suffix(self, pattern, word):
        m = len(pattern)
        n = len(word)
        if m > n:
            return False
        for i in range(m):
            if pattern[i] != word[n-m+i]:
                return False
        return True
    
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                if self.is_prefix(words[i], words[j]) and self.is_suffix(words[i], words[j]):
                    ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = lines[0].split('=')[1].strip()[2:-3].split('","')
            dataset.append(words)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words in dataset:
        results.append(solution.countPrefixSuffixPairs(words))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')