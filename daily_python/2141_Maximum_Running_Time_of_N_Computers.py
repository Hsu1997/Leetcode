import sys
import os
from typing import List

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        left, right = 0, sum(batteries) // n
        while left < right:
            mid = left + (right - left + 1) // 2
            extra = 0
            for battery in batteries:
                extra += min(mid, battery)
            if extra >= mid * n:
                left = mid
            else:
                right = mid - 1
        return left
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            batteries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((n, batteries))
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
    for n, batteries in dataset:
        results.append(solution.maxRunTime(n, batteries))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
