import os
import sys
from typing import List

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if letters[-1] <= target:
            return letters[0]
        for c in letters:
            if c > target:
                return c
        return letters[0]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            letters = lines[0].split('=')[1].strip()[2:-3].split("','")
            target = lines[1].split('=')[1].strip()[1]
            dataset.append((letters, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for letters, target in dataset:
        results.append(solution.nextGreatestLetter(letters, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')