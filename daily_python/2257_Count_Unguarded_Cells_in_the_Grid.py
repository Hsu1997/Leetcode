import os
import sys
from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        unguarded = 0
        guarded = 1
        guard = 2
        wall = 3
        memo = [[unguarded] * n for _ in range(m)]
        for g in guards:
            memo[g[0]][g[1]] = guard
        for w in walls:
            memo[w[0]][w[1]] = wall
        for r in range(m):
            status = unguarded
            for c in range(n):
                if memo[r][c] == unguarded:
                    memo[r][c] = status
                elif memo[r][c] == guarded:
                    continue
                elif memo[r][c] == guard:
                    status = guarded
                elif memo[r][c] == wall:
                    status = unguarded
            status = unguarded
            for c in range(n-1, -1, -1):
                if memo[r][c] == unguarded:
                    memo[r][c] = status
                elif memo[r][c] == guarded:
                    continue
                elif memo[r][c] == guard:
                    status = guarded
                elif memo[r][c] == wall:
                    status = unguarded
        for c in range(n):
            status = unguarded
            for r in range(m):
                if memo[r][c] == unguarded:
                    memo[r][c] = status
                elif memo[r][c] == guarded:
                    continue
                elif memo[r][c] == guard:
                    status = guarded
                elif memo[r][c] == wall:
                    status = unguarded
            status = unguarded
            for r in range(m-1, -1, -1):
                if memo[r][c] == unguarded:
                    memo[r][c] = status
                elif memo[r][c] == guarded:
                    continue
                elif memo[r][c] == guard:
                    status = guarded
                elif memo[r][c] == wall:
                    status = unguarded
        ans = 0
        for i in memo:
            for j in i:
                if j == unguarded:
                    ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            m = int(lines[0].split('=')[1].strip()[:-1])
            n = int(lines[1].split('=')[1].strip()[:-1])
            guards = [list(map(int, line.split(','))) for line in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            walls = [list(map(int, line.split(','))) for line in lines[3].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((m, n, guards, walls))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for m, n, guards, walls in dataset:
        results.append(solution.countUnguarded(m, n, guards, walls))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')