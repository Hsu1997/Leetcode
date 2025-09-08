import os
import sys
from typing import List

class Solution:
    def noZero(self, x: int) -> bool:
        while x:
            if x % 10 == 0:
                return False
            x //= 10
        return True
    
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            if self.noZero(i) and self.noZero(n - i):
                return [i, n - i]
        return [-1, -1]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.getNoZeroIntegers(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')