import os
import sys
from typing import List

class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        k -= 1
        ans = 0
        for op in operations:
            if k % 2 and op:
                ans += 1
            k >>= 1
            if k == 0:
                break
        return chr(ord('a') + (ans % 26))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            k = int(lines[0].split('=')[1].strip()[:-1])
            operations = map(int, lines[1].split('=')[1].strip()[1:-2].split(','))
            dataset.append((k, operations))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for k, operations in dataset:
        results.append(solution.kthCharacter(k, operations))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')