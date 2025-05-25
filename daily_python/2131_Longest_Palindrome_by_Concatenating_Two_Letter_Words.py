import os
import sys
from typing import List
from collections import Counter

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = Counter(words)
        middle = False
        ans = 0
        for temp, c in count.items():
            if temp[0] == temp[1]:
                ans += (c // 2) * 2
                if c % 2 == 1:
                    middle = True
            else:
                if temp[0] < temp[1]:
                    rev = temp[1] + temp[0]
                    if rev in count:
                        ans += 2 * min(c, count[rev])
        return (ans + middle) * 2

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
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
        results.append(solution.longestPalindrome(words))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')