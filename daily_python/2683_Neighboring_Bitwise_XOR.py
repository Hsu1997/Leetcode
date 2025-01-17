import os
import sys
from typing import List

class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        n = len(derived)
        num = 0
        for i in range(n):
            num ^= derived[i]
        return num == 0
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            derived = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(derived)
    return dataset


if __name__ == '__main__':
    if (len(sys.argv)) == 1:
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    solution = Solution()
    results = []
    for derived in dataset:
        results.append(solution.doesValidArrayExist(derived))
    for index, result in enumerate(results):
        print(f'data {index+1} : {result}')
