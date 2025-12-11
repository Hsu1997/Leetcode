import os
import sys
from typing import List

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        x_largest = [0] * (n + 1)
        y_largest = [0] * (n + 1)
        x_smallest = [n + 1] * (n + 1)
        y_smallest = [n + 1] * (n + 1)
        for [x, y] in buildings:
            x_largest[x] = max(x_largest[x], y)
            y_largest[y] = max(y_largest[y], x)
            x_smallest[x] = min(x_smallest[x], y)
            y_smallest[y] = min(y_smallest[y], x)
        ans = 0
        for [x, y] in buildings:
            if x_smallest[x] < y < x_largest[x] and y_smallest[y] < x < y_largest[y]:
                ans += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            buildings = [list(map(int, building.split(','))) for building in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, buildings))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, buildings in dataset:
        results.append(solution.countCoveredBuildings(n, buildings))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')