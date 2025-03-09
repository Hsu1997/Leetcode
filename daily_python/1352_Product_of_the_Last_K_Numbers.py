import os
import sys
from typing import List

class ProductOfNumbers:
    def __init__(self):
        self.prefix = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.prefix = [1]
        else:
            self.prefix.append(num * self.prefix[-1])

    def getProduct(self, k: int) -> int:
        if k >= len(self.prefix):
            return 0
        return self.prefix[-1] // self.prefix[-k-1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            operation = list(lines[0][2:-2].split('","'))
            parameter = [int(p) if p else None for p in lines[1][2:-2].split('],[')]
            dataset.append((operation, parameter))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for operation, parameter in dataset:
        result = []
        for op, pa in zip(operation, parameter):
            if op == 'ProductOfNumbers':
                solution = ProductOfNumbers()
            elif op == 'add':
                solution.add(pa)
            elif op == 'getProduct':
                result.append(solution.getProduct(pa))
        results.append(result)
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    