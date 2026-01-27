import os
import sys
from typing import List

class Solution:
    def dfs(self, u: int) -> None:
        for v in self.e[u]:
            self.dfs(v)
        for parentBought in [0,1]:
            price = self.present[u] // 2 if parentBought == 1 else self.present[u]
            profit = self.future[u] - price
            skip = [self.neg] * (self.budget + 1)
            skip[0] = 0
            for v in self.e[u]:
                for parentCost in range(self.budget, -1, -1):
                    if skip[parentCost] == self.neg:
                        continue
                    for childCost in range(self.budget - parentCost, -1, -1):
                        add = self.dp[v][childCost][0]
                        if add == self.neg:
                            continue
                        skip[parentCost + childCost] = max(skip[parentCost + childCost], skip[parentCost] + add)

            take = [self.neg] * (self.budget + 1)
            if price <= self.budget:
                take[price] = 0
            for v in self.e[u]:
                for parentCost in range(self.budget, -1, -1):
                    if take[parentCost] == self.neg:
                        continue
                    for childCost in range(self.budget - parentCost, -1, -1):
                        add = self.dp[v][childCost][1]
                        if add == self.neg:
                            continue
                        take[parentCost + childCost] = max(take[parentCost + childCost], take[parentCost] + add)
            for b in range(price, self.budget + 1):
                if take[b] != self.neg:
                    take[b] += profit
            for b in range(self.budget + 1):
                self.dp[u][b][parentBought] = max(skip[b], take[b])
        return
    
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        self.e = [[] for _ in range(n)]
        for r in hierarchy:
            if not r:
                continue
            self.e[r[0]-1].append(r[1]-1)
        self.n = n
        self.present = present
        self.future = future
        self.budget = budget
        self.neg = -10**18
        self.dp = [[[self.neg] * 2 for _ in range(budget + 1)] for _ in range(n)]
        self.dfs(0)
        return max(self.dp[0][i][0] for i in range(budget + 1))

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            present = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            future = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            hierarchy = [list(map(int, w.split(','))) if w else None for w in lines[3].split('=')[1].strip()[2:-3].split('},{')]
            budget = int(lines[4].split('=')[1].strip()[:-1])
            dataset.append((n, present, future, hierarchy, budget))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, present, future, hierarchy, budget in dataset:
        results.append(solution.maxProfit(n, present, future, hierarchy, budget))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')