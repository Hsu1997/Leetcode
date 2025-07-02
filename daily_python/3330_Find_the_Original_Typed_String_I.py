import os
import sys
from typing import List

class Solution:
    def possibleStringCount(self, word: str) -> int:
        n = len(word)
        ans = 1
        for i in range(1, n):
            if word[i-1] == word[i]:
                ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(word)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word in dataset:
        results.append(solution.possibleStringCount(word))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')