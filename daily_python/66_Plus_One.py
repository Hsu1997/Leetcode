import os
import sys
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        carry = 1
        for i in range(n - 1, -1, -1):
            if carry == 0:
                return digits
            digits[i] += carry
            carry = digits[i] // 10
            digits[i] %= 10
        if carry == 1:
            digits = [1] + digits
        return digits

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            digits = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(digits)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for digits in dataset:
        results.append(solution.plusOne(digits))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
