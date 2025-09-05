import os
import sys
from typing import List

class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        round = 1
        num1 -= num2
        while num1 >= round:
            if bin(num1).count('1') <= round:
                return round
            num1 -= num2
            round += 1
        return -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num1 = int(lines[0].split('=')[1].strip()[:-1])
            num2 = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((num1, num2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num1, num2 in dataset:
        results.append(solution.makeTheIntegerZero(num1, num2))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')