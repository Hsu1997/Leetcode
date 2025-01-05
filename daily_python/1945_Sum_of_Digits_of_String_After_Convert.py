import os
import sys
from typing import List

class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num_str = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        for _ in range(k):
            num_str = str(sum(int(char) for char in num_str))
        return int(num_str)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.getLucky(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')