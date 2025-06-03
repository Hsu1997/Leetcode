import os
import sys
from typing import List
from collections import deque

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n = len(candies)
        ans = 0
        visited = [0] * n
        hasKey = [0] * n
        hasBox = [0] * n
        que = deque([])
        for b in initialBoxes:
            hasBox[b] = 1
            if status[b] == 1:
                que.append(b)
                visited[b] = 1
        while que:
            curr = que.popleft()
            ans += candies[curr]
            for key in keys[curr]:
                hasKey[key] = 1
                if not visited[key] and hasBox[key]:
                    visited[key] = 1
                    que.append(key)
            for box in containedBoxes[curr]:
                hasBox[box] = 1
                if not visited[box] and (status[box] == 1 or hasKey[box]):
                    visited[box] = 1
                    que.append(box)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            status = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            candies = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            keys = [list(map(int, enum.split(','))) if enum else [] for enum in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            containedBoxes = [list(map(int, enum.split(','))) if enum else [] for enum in lines[3].split('=')[1].strip()[2:-3].split('},{')]
            initialBoxes = list(map(int, lines[4].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((status, candies, keys, containedBoxes, initialBoxes))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for status, candies, keys, containedBoxes, initialBoxes in dataset:
        results.append(solution.maxCandies(status, candies, keys, containedBoxes, initialBoxes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')