import os
import sys
from typing import List

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        last_day = days[-1]
        memo = [0] * (last_day+1)
        idx = 0
        for day in range(1, last_day+1):
            if day < days[idx]:
                memo[day] = memo[day - 1]
            else:
                idx += 1
                memo[day] = min(costs[0] + memo[day - 1], costs[1] + memo[max(0, day - 7)], costs[2] + memo[max(0, day - 30)])
        return memo[last_day]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            days = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            costs = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((days, costs))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for days, costs in dataset:
        results.append(solution.mincostTickets(days, costs))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')