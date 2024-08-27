import os
import sys
from typing import List
from collections import defaultdict
import heapq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        e = defaultdict(list)
        for i, (u,v) in enumerate(edges):
            e[u].append((v, succProb[i]))
            e[v].append((u, succProb[i]))
        maxProb = [0.0] * n
        maxProb[start_node] = 1.0
        pq = []
        heapq.heappush(pq, (-1.0, start_node))
        round = 0
        while round < n and pq:
            curr_prob, curr_node = heapq.heappop(pq)
            if curr_node == end_node:
                return -curr_prob
            for neighbor, pathsucc in e[curr_node]:
                if maxProb[neighbor] < pathsucc * -curr_prob:
                    maxProb[neighbor] = pathsucc * -curr_prob
                    heapq.heappush(pq, (-maxProb[neighbor], neighbor))
        return 0.0

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            pairs = lines[1].split('=')[1][3:-3].split('},{')
            edges = [list(map(int, pair.split(','))) for pair in pairs]
            succProb = list(map(float, lines[2].split('=')[1][2:-2].split(',')))
            start_node = int(lines[3].split('=')[1].strip()[:-1])
            end_node = int(lines[4].split('=')[1].strip()[:-1])
            dataset.append((n, edges, succProb, start_node, end_node))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, edges, succProb, start_node, end_node in dataset:
        results.append(solution.maxProbability(n, edges, succProb, start_node, end_node))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')