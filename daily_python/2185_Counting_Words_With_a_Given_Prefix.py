import os
import sys
from typing import List

class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(word.startswith(pref) for word in words)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = lines[0].split('=')[1].strip()[2:-3].split('","')
            pref = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((words, pref))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, pref in dataset:
        results.append(solution.prefixCount(words, pref))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')