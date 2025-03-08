import os
import sys
from typing import List

class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        white = sum(1 if blocks[i] == 'W' else 0 for i in range(k))
        ans = white
        for i in range(k, len(blocks)):
            white = white + (blocks[i] == 'W') - (blocks[i-k] == 'W')
            ans = min(ans, white)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            b = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((b, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for b, k in dataset:
        results.append(solution.minimumRecolors(b, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')