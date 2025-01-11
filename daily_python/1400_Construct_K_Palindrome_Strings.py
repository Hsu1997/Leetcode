import sys
import os
from typing import List

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        odd = 0
        for i in count:
            if i % 2:
                odd += 1
        return odd <= k

def readDataInFile(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == "__main__":
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataInFile(filename)
    solution = Solution()
    results = []
    for s, k in dataset:
        results.append(solution.canConstruct(s, k))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')