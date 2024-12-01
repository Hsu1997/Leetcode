import os
import sys
from typing import List
from collections import defaultdict, deque

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        in_degree, out_degree = defaultdict(int), defaultdict(int)
        adj = defaultdict(deque)
        for pair in pairs:
            start, end = pair[0], pair[1]
            in_degree[end] += 1
            out_degree[start] += 1
            adj[start].append(end)

        start_node = -1
        for node in out_degree:
            if out_degree[node] == in_degree[node] + 1:
                start_node = node
                break
        if start_node == -1:
            start_node = pairs[0][0]

        def visit(node):
            while adj[node]:
                next_node = adj[node].popleft()
                visit(next_node)
            results.append(node)

        results = []
        visit(start_node)
        results.reverse()
        ans = [[results[i-1], results[i]] for i in range(1, len(results))]

        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            pairs = [list(map(int, i.split(','))) for i in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(pairs)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for pairs in dataset:
        results.append(solution.validArrangement(pairs))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')