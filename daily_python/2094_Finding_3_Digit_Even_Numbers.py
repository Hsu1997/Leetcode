import os
import sys
from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        count = [0] * 10
        for d in digits:
            count[d] += 1
        ans = []
        for i in range(100, 1000, 2):
            single = i % 10
            ten = (i % 100) // 10
            hundred = i // 100
            count[single] -= 1
            count[ten] -= 1
            count[hundred] -= 1
            if count[single] >= 0 and count[ten] >= 0 and count[hundred] >= 0:
                ans.append(i)
            count[single] += 1
            count[ten] += 1
            count[hundred] += 1
        return ans
    
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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for digits in dataset:
        results.append(solution.findEvenNumbers(digits))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')