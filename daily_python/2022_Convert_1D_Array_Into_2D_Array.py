import os
import sys
from typing import List

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        table = [[0] * n for _ in range(m)]
        for index, num in enumerate(original):
            table[index // n][index % n] = num
        return table

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            original = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            m = int(lines[1].split('=')[1].strip()[:-1])
            n = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((original, m, n))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for original, m, n in dataset:
        results.append(solution.construct2DArray(original, m, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
