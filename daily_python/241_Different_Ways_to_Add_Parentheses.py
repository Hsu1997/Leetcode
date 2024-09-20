import os
import sys
from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        if not expression:
            return []
        if len(expression) < 3:
            return [int(expression)]
        results = []
        for index, char in enumerate(expression):
            if char.isdigit():
                continue
            left = self.diffWaysToCompute(expression[:index])
            right = self.diffWaysToCompute(expression[index+1:])
            for l in left:
                for r in right:
                    if char == '+':
                        results.append(l + r)
                    elif char == '-':
                        results.append(l - r)
                    else:
                        results.append(l * r)
        return results
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            expression = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(expression)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for expression in dataset:
        results.append(solution.diffWaysToCompute(expression))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')