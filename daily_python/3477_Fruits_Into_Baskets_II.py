import os
import sys
from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unplaced = 0
        n = len(baskets)
        for f in fruits:
            unfinded = 1
            for j in range(n):
                if baskets[j] >= f:
                    baskets[j] = 0
                    unfinded = 0
                    break
            unplaced += (unfinded == 1)
        return unplaced

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            fruits = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            baskets = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((fruits, baskets))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for fruits, baskets in dataset:
        results.append(solution.numOfUnplacedFruits(fruits, baskets))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')