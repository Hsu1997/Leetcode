import sys
import os
from typing import List

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        curr = set()
        ans = set()
        for x in arr:
            curr = {x | c for c in curr} | {x}
            ans |= curr
        return len(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(arr)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.subarrayBitwiseORs(arr))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')