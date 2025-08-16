import os
import sys
from typing import List

class Solution:
    def maximum69Number (self, num: int) -> int:
        divisor = 1000
        while divisor:
            if num // divisor % 10 == 6:
                num += divisor * 3
                return num
            divisor //= 10
        return num        
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.maximum69Number(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')