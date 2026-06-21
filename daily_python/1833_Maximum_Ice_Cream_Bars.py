import os
import sys
from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        M = max(costs)
        cnt = [0] * (M + 1)
        for c in costs:
            cnt[c] += 1
        ans = 0
        for c in range(1, M + 1):
            curr = min(cnt[c], coins // c)
            ans += curr
            coins -= curr * c
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            costs = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            coins = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((costs, coins))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for costs, coins in dataset:
        results.append(solution.maxIceCream(costs, coins))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')