import sys
import os
from typing import List

class Solution:
    def numberOfWays(self, corridor: str) -> int:
        ans = 1
        mod = 10**9 + 7
        cnt = 0
        last = -1
        for idx, c in enumerate(corridor):
            if c == 'S':
                cnt += 1
                if cnt >= 2 and cnt % 2 == 1:
                    ans = (ans * (idx - last)) % mod
                last = idx
        if cnt == 0 or cnt % 2 == 1:
            return 0
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            corridor = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(corridor)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for corridor in dataset:
        results.append(solution.numberOfWays(corridor))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
