import sys
import os
from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        maxElement = arrays[0][-1]
        minElement = arrays[0][0]
        maxDistance = 0
        for i in range(1, len(arrays)):
            temp = arrays[i]
            maxDistance = max(maxDistance, abs(maxElement - temp[0]), abs(temp[-1] - minElement))
            maxElement = max(maxElement, temp[-1])
            minElement = min(minElement, temp[0])
        return maxDistance

def readDataSet(filename: str)-> None:
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arrays = eval(lines[0].split('=')[1].strip()[:-1].replace('{','[').replace('}',']'))
            dataset.append(arrays)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arrays in dataset:
        results.append(solution.maxDistance(arrays))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
