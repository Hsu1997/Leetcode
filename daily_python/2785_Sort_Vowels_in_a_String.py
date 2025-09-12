import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def is_vowel(self, c) -> bool:
        return c in 'AEIOUaeiou'
    
    def sortVowels(self, s: str) -> str:
        cnt = defaultdict(int)
        vowel = 'AEIOUaeiou'
        for c in s:
            if self.is_vowel(c):
                cnt[c] += 1
        res = []
        j = 0
        for c in s:
            if self.is_vowel(c):
                while cnt[vowel[j]] == 0:
                    j += 1
                res.append(vowel[j])
                cnt[vowel[j]] -= 1
            else:
                res.append(c)
        return "".join(res)

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
        results.append(solution.sortVowels(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')