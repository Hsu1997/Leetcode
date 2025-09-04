import os
import sys

class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        a = abs(x - z)
        b = abs(y - z)
        return 0 if a == b else 1 if a < b else 2

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            x = int(lines[0].split('=')[1].strip()[:-1])
            y = int(lines[1].split('=')[1].strip()[:-1])
            z = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((x, y, z))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for x, y, z in dataset:
        results.append(solution.findClosest(x, y, z))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')