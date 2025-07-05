import os
import sys
from typing import List

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cnt = {}
        for val in arr:
            cnt[val] = cnt.get(val, 0) + 1
        ans = -1
        for val, c in cnt.items():
            if val == c:
                ans = max(ans, val)
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
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.findLucky(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
    