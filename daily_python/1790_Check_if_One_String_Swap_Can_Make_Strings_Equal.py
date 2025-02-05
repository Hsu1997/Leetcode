import os
import sys
from typing import List

class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        diff = 0
        first_index = -1
        second_index = -1
        for i, c1, c2 in zip(range(len(s1)), s1, s2):
            if c1 != c2:
                diff += 1
                if diff > 2:
                    return False
                elif diff == 1:
                    first_index = i
                else:
                    second_index = i
        return (s1[first_index] == s2[second_index]) and (s1[second_index] == s2[first_index])
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s1 = lines[0].split('=')[1].strip()[1:-2]
            s2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s1, s2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s1, s2 in dataset:
        results.append(solution.areAlmostEqual(s1, s2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')