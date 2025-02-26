import os
import sys
from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        odd = 0
        even = 0
        ans = 0
        mod = 1e9 + 7
        for num in arr:
            if num % 2 == 0:
                odd = odd
                even += 1
            else:
                odd, even = even, odd
                odd += 1
            ans = (ans + odd) % mod
        return int(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(arr)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.numOfSubarrays(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')