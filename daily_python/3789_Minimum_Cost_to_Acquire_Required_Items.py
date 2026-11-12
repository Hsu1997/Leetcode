import os
import sys
from typing import List

class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if cost1 + cost2 <= costBoth:
            return cost1 * need1 + cost2 * need2
        need3 = min(need1, need2)
        res = need3 * costBoth
        need1 -= need3
        need2 -= need3
        res += min(cost1, costBoth) * need1 + min(cost2, costBoth) * need2
        return res

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            cost1 = int(lines[0].split('=')[1].strip()[:-1])
            cost2 = int(lines[1].split('=')[1].strip()[:-1])
            costBoth = int(lines[2].split('=')[1].strip()[:-1])
            need1 = int(lines[3].split('=')[1].strip()[:-1])
            need2 = int(lines[4].split('=')[1].strip()[:-1])
            dataset.append((cost1, cost2, costBoth, need1, need2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for cost1, cost2, costBoth, need1, need2 in dataset:
        results.append(solution.minimumCost(cost1, cost2, costBoth, need1, need2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')