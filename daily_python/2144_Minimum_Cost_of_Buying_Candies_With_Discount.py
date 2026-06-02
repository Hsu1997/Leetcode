import sys
import os
from typing import List

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(key = lambda x : -x)
        ans = sum(cost)
        n = len(cost)
        for i in range(2, n, 3):
            ans -= cost[i]
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            cost = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(cost)
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
    for cost in dataset:
        results.append(solution.minimumCost(cost))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
