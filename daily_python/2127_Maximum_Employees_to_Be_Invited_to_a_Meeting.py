import os
import sys
from typing import List
from collections import deque

class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        indegree = [0] * n
        for dest in favorite:
            indegree[dest] += 1
        que = deque()
        for source in range(n):
            if indegree[source] == 0:
                que.append(source)
        depth = [1] * n
        while que:
            curr = que.popleft()
            dest = favorite[curr]
            depth[dest] = max(depth[dest], depth[curr] + 1)
            indegree[dest] -= 1
            if indegree[dest] == 0:
                que.append(dest)
        longest_cycle = 0
        two_cycle = 0
        for source in range(n):
            if indegree[source] == 0:
                continue
            curr_cycle = 0
            curr = source
            while indegree[curr] != 0:
                indegree[curr] = 0
                curr_cycle += 1
                curr = favorite[curr]
            if curr_cycle == 2:
                two_cycle += depth[source] + depth[favorite[source]]
            else:
                longest_cycle = max(longest_cycle, curr_cycle)
        return max(longest_cycle, two_cycle)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            favorite = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(favorite)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for favorite in dataset:
        results.append(solution.maximumInvitations(favorite))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')