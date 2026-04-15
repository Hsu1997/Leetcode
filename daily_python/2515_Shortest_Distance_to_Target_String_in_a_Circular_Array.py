import os
import sys
from typing import List

class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        for dis in range(0, n // 2 + 2):
            if words[(startIndex + dis) % n] == target or words[(startIndex + n - dis) % n] == target:
                return dis
        return -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            target = lines[1].split('=')[1].strip()[1:-2]
            startIndex = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((words, target, startIndex))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, target, startIndex in dataset:
        results.append(solution.closestTarget(words, target, startIndex))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')