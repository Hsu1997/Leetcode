import os
import sys
from typing import List

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        for s in text.split(' '):
            valid = True
            for c in s:
                if c in brokenLetters:
                    valid = False
                    break
            if valid:
                ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            text = lines[0].split('=')[1].strip()[1:-2]
            brokenLetters = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((text, brokenLetters))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for text, brokenLetters in dataset:
        results.append(solution.canBeTypedWords(text, brokenLetters))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')