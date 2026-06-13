import os
import sys
from typing import List

class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        return "".join([chr(ord('a') + 25 - sum(weights[ord(c) - ord('a')] for c in word) % 26) for word in words])
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            weights = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((words, weights))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, weights in dataset:
        results.append(solution.mapWordWeights(words, weights))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')