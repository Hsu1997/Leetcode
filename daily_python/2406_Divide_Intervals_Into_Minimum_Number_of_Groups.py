import os
import sys
from typing import List

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        M = float("-inf")
        m = float("inf")
        for interval in intervals:
            M = max(M, interval[1])
            m = min(m, interval[0])
        count = [0] * (M + 2)
        for interval in intervals:
            count[interval[0]] += 1
            count[interval[1]+1] -= 1
        ans = 0
        acc = 0
        for c in count:
            acc += c
            ans = max(ans, acc)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            intervals = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(intervals)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for intervals in dataset:
        results.append(solution.minGroups(intervals))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')