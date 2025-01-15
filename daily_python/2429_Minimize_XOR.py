import os
import sys
from typing import List

class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        bit = 0
        zero = 0
        one = 0
        while (num1 >> bit) or (num2 >> bit):
            if (num2 >> bit) & 1:
                one += 1
            else:
                zero += 1
            bit += 1
        ans = 0
        bit -= 1
        while zero > 0 and one > 0:
            if (num1 >> bit) & 1:
                ans |= (1 << bit)
                one -= 1
            else:
                zero -= 1
            bit -= 1
        while one > 0 and bit >= 0:
            ans |= (1 << bit)
            one -= 1
            bit -= 1
        return ans

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
        results.append(solution.minimizeXor(num1, num2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')