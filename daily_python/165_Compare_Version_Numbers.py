import os
import sys
from typing import List

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        n1 = [int(i) for i in version1.split('.')]
        n2 = [int(i) for i in version2.split('.')]
        for i in range(max(len(n1), len(n2))):
            num1 = n1[i] if i < len(n1) else 0
            num2 = n2[i] if i < len(n2) else 0
            if num1 != num2:
                return -1 if num1 < num2 else 1
        return 0

def readDataSet(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            version1 = lines[0].split('=')[1].strip()[1:-2]
            version2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((version1, version2))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for version1, version2 in dataset:
        results.append(solution.compareVersion(version1, version2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
