import os
import sys
from typing import List
from collections import deque

class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)
        self.bob_path = []
        self.graph = [[] for _ in range(n)]
        self.visited = [False] * n

        for edge in edges:
            self.graph[edge[0]].append(edge[1])
            self.graph[edge[1]].append(edge[0])

        self.find_bob_path(bob)
        
        ans = float('-inf')
        que = deque([0])
        dp = [float('-inf')] * n
        dp[0] = amount[0]
        amount[bob] = 0
        time = 1

        while que:
            candidate = len(que)
            if time < len(self.bob_path):
                amount[self.bob_path[time]] /= 2
            for _ in range(candidate):
                curr = que.popleft()
                for neighbor in self.graph[curr]:
                    if dp[neighbor] == float('-inf'):
                        dp[neighbor] = dp[curr] + amount[neighbor]
                        que.append(neighbor)
                        if len(self.graph[neighbor]) == 1:
                            ans = max(ans, dp[neighbor])
            if time < len(self.bob_path):
                amount[self.bob_path[time]] = 0
            time += 1
        return int(ans)
    def find_bob_path(self, pos):
        self.bob_path.append(pos)
        self.visited[pos] = True
        if pos == 0:
            return True
        for neighbor in self.graph[pos]:
            if not self.visited[neighbor] and self.find_bob_path(neighbor):
                return True
        self.bob_path.pop()
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            edges = [list(map(int, edge.split(','))) for edge in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            bob = int(lines[1].split('=')[1].strip()[:-1])
            amount = list(map(int, lines[2].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((edges, bob, amount))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for edges, bob, amount in dataset:
        results.append(solution.mostProfitablePath(edges, bob, amount))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')