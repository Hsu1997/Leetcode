import sys
import os
from typing import List

class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return n * m // 2
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            m = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, m))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    results = []
    solution = Solution()
    dataset = readDataSet(filename)
    for n, m in dataset:
        results.append(solution.flowerGame(n, m))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')