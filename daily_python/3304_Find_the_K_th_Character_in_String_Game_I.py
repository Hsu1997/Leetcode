import os
import sys
from typing import List

class Solution:
    def kthCharacter(self, k: int) -> str:
        k -= 1
        ans = 0
        while k:
            if k % 2 == 1:
                ans += 1
            k //= 2
        return chr(ord('a') + (ans % 26))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            k = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(k)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for k in dataset:
        results.append(solution.kthCharacter(k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')