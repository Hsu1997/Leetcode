import sys
import os
from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        m, M, curr = 0, 0, 0
        for d in differences:
            curr += d
            m = min(m, curr)
            M = max(M, curr)
        return ((upper - lower) - (M - m) + 1) if ((upper - lower) - (M - m) + 1) > 0 else 0
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            differences = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            lower = int(lines[1].split('=')[1].strip()[:-1])
            upper = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((differences, lower, upper))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for differences, lower, upper in dataset:
        results.append(solution.numberOfArrays(differences, lower, upper))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
