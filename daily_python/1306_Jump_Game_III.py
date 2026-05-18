import os
import sys
from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = [False] * n
        que = [start]
        visited[start] = True
        while que:
            curr = que.pop(0)
            if arr[curr] == 0:
                return True
            if curr - arr[curr] >= 0 and not visited[arr[curr]]:
                visited[arr[curr]] = True
                que.append(arr[curr])
            if curr + arr[curr] < n and not visited[arr[curr]]:
                visited[arr[curr]] = True
                que.append(arr[curr])
        return False

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            start = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((arr, start))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, start in dataset:
        results.append(solution.canReach(arr, start))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')