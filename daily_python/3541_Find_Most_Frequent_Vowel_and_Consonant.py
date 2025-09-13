import os
import sys
from typing import List
from collections import Counter

class Solution:
    def is_vowel(self, c: chr) -> bool:
        return c in 'aeiou'
    
    def maxFreqSum(self, s: str) -> int:
        cnt = Counter(s)
        v = 0
        c = 0
        for char, freq in cnt.items():
            if self.is_vowel(char):
                v = max(v, freq)
            else:
                c = max(c, freq)
        return v + c

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
        results.append(solution.maxFreqSum(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')