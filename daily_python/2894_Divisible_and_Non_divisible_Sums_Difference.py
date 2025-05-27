import os
import sys

class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        group = n // m
        return (1 + n) * n // 2 - m * (1 + group) * group

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((m, n))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n in dataset:
        results.append(solution.differenceOfSums(m, n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')