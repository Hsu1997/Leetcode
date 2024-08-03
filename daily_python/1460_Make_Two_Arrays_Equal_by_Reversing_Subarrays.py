import os
import sys
from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        count = {}
        for n in target:
            if (n not in count):
                count[n] = 1
            else:
                count[n] += 1
        for n in arr:
            if (n not in count):
                return False
            count[n] -= 1
        for c in count:
            if count[c] != 0:
                return False
        return True

def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            target = list(map(int,lines[0].split('=')[1].strip()[1:-2].split(',')))
            arr = list(map(int,lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((target, arr))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    print(dataset)
    solution = Solution()
    results = []
    for target, arr in dataset:
        results.append(solution.canBeEqual(target, arr))
    for index, result in enumerate(results):
        print(f'data {index+1} : {result}')