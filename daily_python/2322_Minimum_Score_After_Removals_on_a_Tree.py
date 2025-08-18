import os
import sys
from typing import List

class Solution:
    def dfs(self, n: int, p: int) -> None:
        self.tin[n] = self.t
        self.t += 1
        curr = self.nums[n]
        for neighbor in self.graph[n]:
            if neighbor == p:
                continue
            self.dfs(neighbor, n)
            curr ^= self.acc[neighbor]
        self.acc[n] = curr
        self.tout[n] = self.t
        self.t += 1

    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        self.graph = [[] for _ in range(n)]
        self.tin = [0] * n
        self.tout = [0] * n
        self.acc = [0] * n
        self.t = 0
        for s, e in edges:
            self.graph[s].append(e)
            self.graph[e].append(s)
        self.nums = nums
        self.dfs(0, -1)
        ans = float('inf')
        for i in range(1, n):
            for j in range(i+1, n):
                if self.tin[i] < self.tin[j] < self.tout[i]:
                    ans = min(ans, max(self.acc[0] ^ self.acc[i], self.acc[i] ^ self.acc[j], self.acc[j]) - min(self.acc[0] ^ self.acc[i], self.acc[i] ^ self.acc[j], self.acc[j]))
                elif self.tin[j] < self.tin[i] < self.tout[j]:
                    ans = min(ans, max(self.acc[0] ^ self.acc[j], self.acc[j] ^ self.acc[i], self.acc[i]) - min(self.acc[0] ^ self.acc[j], self.acc[j] ^ self.acc[i], self.acc[i]))
                else:
                    ans = min(ans, max(self.acc[0] ^ self.acc[i] ^ self.acc[j], self.acc[i], self.acc[j]) - min(self.acc[0] ^ self.acc[i] ^ self.acc[j], self.acc[i], self.acc[j]))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            edges = [list(map(int, edge.split(','))) for edge in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((nums, edges))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, edges in dataset:
        results.append(solution.minimumScore(nums, edges))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')