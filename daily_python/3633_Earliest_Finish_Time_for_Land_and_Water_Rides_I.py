import os
import sys
from typing import List

class Solution:
    def solve(self, s1: List[int], d1: List[int], s2: List[int], d2: List[int]) -> int:
        m, n = len(s1), len(s2)
        e1 = float('inf')
        ans = float('inf')
        for i in range(m):
            e1 = min(e1, s1[i] + d1[i])
        for i in range(n):
            ans = min(ans, max(e1, s2[i]) + d2[i])
        return ans

    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        m, n = len(landStartTime), len(waterStartTime)
        return min(self.solve(landStartTime, landDuration, waterStartTime, waterDuration), self.solve(waterStartTime, waterDuration, landStartTime, landDuration))

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            landStartTime = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            landDuration = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            waterStartTime = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            waterDuration = list(map(int, lines[3].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((landStartTime, landDuration, waterStartTime, waterDuration))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for landStartTime, landDuration, waterStartTime, waterDuration in dataset:
        results.append(solution.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')