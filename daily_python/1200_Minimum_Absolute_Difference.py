import os
import sys
from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        m = float('inf')
        ans = []
        for i in range(1, n):
            d = arr[i] - arr[i-1]
            if d < m:
                m = d
                ans = [[arr[i-1], arr[i]]]
            elif d == m:
                ans.append([arr[i-1], arr[i]])
            else:
                continue
        return ans

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
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.minimumAbsDifference(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')